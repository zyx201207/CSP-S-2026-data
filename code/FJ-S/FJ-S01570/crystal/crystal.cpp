#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=5e5+5;
int n;
ll m,a[maxn];
int cnt[maxn];
inline int read(){
	ll x=0;
	int f=0;
	char c=getchar();
	while(c<'0' || c>'9'){
		f=1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	if(f)x=-x;
	return x;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		cnt[i]=1;
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;++i){
		ll maxe=m;
		int j=i-1;
		if(a[i]==a[j]){
			cnt[i]=cnt[j]+1;
			continue;
		}
		for(;j>=0 && a[i]-a[j]<=maxe;--j){
			maxe-=a[i]-a[j];
			cnt[i]++;
		}
	}
	int M=-1;
	for(int i=1;i<=n;i++){
		M=max(M,cnt[i]);
	}
	cout<<M;
	return 0;
}
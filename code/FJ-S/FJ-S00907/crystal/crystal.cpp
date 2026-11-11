#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=1e6+5;
inline int read(){
	char c;
	int x=0,f=1;
	c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m,a[MAXN];
int pre[MAXN];
bool check(int x){
	for(int i=x;i<=n;i++){
		int st=i-x+1;
		int summ=(x-1)*a[i];
		int now=pre[i-1]-pre[st-1];
		if(summ-now<=m) return true;
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)/2;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l<<endl;
	return 0;
}

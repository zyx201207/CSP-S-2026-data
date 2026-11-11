#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int sum=0,f=1;
	char ch=getchar();
	while(!(ch>='0'&&ch<='9')){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		sum=(sum<<3)+(sum<<1)+ch-'0';
		ch=getchar();
	}
	return sum*f;
}
int n,m;
int a[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	sort(a+1,a+1+n);
	int j=1,ans=1,last=0;
	for(int i=2;i<=n;++i){
		while(last+(a[i]-a[i-1])*(i-j)>m){
			last-=a[i-1]-a[j];
			++j;
		}
		last+=(a[i]-a[i-1])*(i-j);
		ans=max(ans,i-j+1);
	}
	printf("%lld",ans);
}

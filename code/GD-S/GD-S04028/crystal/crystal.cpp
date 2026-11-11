#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define gc getchar
long long read(){
	short f=1,c=gc();
	long long x=0;
	while(c!=0&&(c<'0'&&c>'9')){
		if(c==EOF)return 0;
		c=gc();
	}if(c=='-'){f=-1;c=gc();}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=gc();
	}return x*f;
}
int n;
ll a[500002],m,ans=-4e18;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}sort(a+1,a+1+n);
	
	ll sum,sm[500002]={0};
	for(int l=1,r=1;r<=n;){
		sum=0;
		sm[r]=sm[r-1]+a[r];
		sum+=a[r]*(r-l+1ll);
//		for(int i=l;i<=r;++i)sum-=a[i];
		sum-=sm[r]-sm[l-1];
		if(sum<=m)ans=max(ans,r-l+1ll),++r;
		else
			sum-=(a[r]-a[l++]);
	}printf("%lld",ans);
}

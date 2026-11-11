#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define ll long long
#define il inline
#define re register int
#define rl register ll
#define gc getchar
using namespace std;
const int MN=2e6+5;
ll n,d,a[MN],f[MN],g[MN],ans,s[MN];
il ll read(){ll x=0,f=1;char ch=gc();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=gc();}while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=gc();}return x*f;}
il void write(rl x){if(x<0){putchar('-');write(-x);return;}if(x>9)write(x/10);putchar(x%10+'0');}
il void solve6(){
	n=read();d=read();ans=0;
	for(re i=1; i<=n; ++i) a[i]=read();
	for(re l=1; l<=n; ++l){
		for(re i=l; i<=n; ++i) f[i]=1e18,g[i]=0;
		f[l]=0,g[l]=1;
		for(re r=l+1; r<=n; ++r){
			for(re i=r-1; i>=l; --i) if(a[r]-a[i]<=d){
				if(f[i]+1<f[r]) f[r]=f[i]+1,g[r]=g[i];
				else if(f[i]+1==f[r]) g[r]+=g[i];
			}
			else break;
		}
//		for(re i=l; i<=n; ++i) cout<<f[i]<<' ';cout<<'\n';
//		for(re i=l; i<=n; ++i) cout<<g[i]<<' ';cout<<'\n'; 
		for(re i=l; i<=n; ++i) if(g[i]==2) ++ans;
	}
	write(ans);putchar('\n');
}
il void solve10(){
	n=read();d=read();ans=0;
	for(re i=1; i<=n; ++i) a[i]=read();
	for(re l=1; l<=n; ++l){
		for(re i=l; i<=n; ++i) f[i]=1e18,g[i]=0;
		f[l]=0,s[l]=g[l]=1;s[l-1]=0;
		for(re r=l+1; r<=n; ++r){
			ll x=lower_bound(a+1,a+1+n,a[r]-d)-a,y=upper_bound(f+x,f+r,f[x])-f;
			if(f[y]>f[x]) --y;
//			cout<<x<<' '<<y<<'\n';
			f[r]=f[x]+1;g[r]=s[y]-s[x-1];s[r]=s[r-1]+g[r];
			if(g[r]==2) ++ans;
		}
//		for(re i=l; i<=n; ++i) cout<<f[i]<<' ';cout<<'\n';
//		for(re i=l; i<=n; ++i) cout<<g[i]<<' ';cout<<'\n'; 
	}
	write(ans);putchar('\n');
}
il void solve12(){
	n=read();d=read();ans=0;
	for(re i=1; i<=n; ++i) a[i]=read(),f[i]=1e18,g[i]=0;
	f[1]=0;s[1]=g[1]=1;s[0]=0;ll cnt=0;
	for(re r=2; r<=n; ++r){
		ll x=lower_bound(a+1,a+1+n,a[r]-d)-a,y=upper_bound(f+x,f+r,f[x])-f;
		if(f[y]>f[x]) --y;
//		cout<<x<<' '<<y<<'\n';
		f[r]=f[x]+1;g[r]=s[y]-s[x-1];s[r]=s[r-1]+g[r];
		if(g[r]==2) ++cnt;ans+=cnt;
	}
//	for(re i=1; i<=n; ++i) cout<<f[i]<<' ';cout<<'\n';
//	for(re i=1; i<=n; ++i) cout<<g[i]<<' ';cout<<'\n'; 
	write(ans);putchar('\n');
}
/*
0 1
5 5
1 3 5 7 9
*/
il void solve(){}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll cid=read(),T=read();
	if(cid<=6){while(T--)solve6();return 0;}
	if(cid<=10){while(T--)solve10();return 0;}
	if(cid<=12){while(T--)solve12();return 0;}
	while(T--)solve10();
	return 0;
}//261031


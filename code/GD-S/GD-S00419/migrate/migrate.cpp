#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
int C,t,n,a[N],b[N],c[N];
ll d,x[N],ans,f[N],g[N],h[N];
ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	C=read(),t=read();
	while(t--){
		n=read(),d=read();
		for(int i=1;i<=n;i++)
			x[i]=read(),f[i]=g[i]=h[i]=0;
		x[0]=-4e18;ans=0;
		int r=1,pr=1,ppr=1;
		for(int i=1;i<=n;i++){
			while(r<n&&x[r+1]-x[i]<=d)r++;
			while(pr<n&&x[pr+1]-x[i-1]<=d)pr++;
			while(ppr<n&&i>2&&x[ppr+1]-x[i-2]<=d)ppr++;
			ppr=max(ppr,i);
			a[i]=r,b[i]=pr,c[i]=ppr;
			
		}
		for(int i=n;i>0;i--){
			if(a[i]==i){
				continue;
			}
			if(b[i]+1<a[i])h[i]=g[a[i]];
			if(b[i]<a[i])h[i]+=h[a[i]],f[i]=f[a[i]];
			else if(c[i]<b[i])g[i]=f[a[i]];
			f[i]+=a[i]-b[i],g[i]+=b[i]-c[i];
			ans+=h[a[i]]+g[a[i]];
//			cout<<i<<' '<<ans<<' '<<g[i]<<' '<<b[i]-c[i]<<' '<<f[a[i]]<<endl;
		}
//		for(int i=1;i<=n;i++){
//			cout<<a[i]<<' '<<b[i]<<' '<<c[i]<<' '<<f[i]<<' '<<g[i]<<' '<<h[i]<<endl;
//		}
		printf("%lld\n",ans);
	}
	
	return 0;
} 

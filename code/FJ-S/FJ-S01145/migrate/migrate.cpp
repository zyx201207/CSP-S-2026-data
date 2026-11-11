#include<bits/stdc++.h>
using ll=long long;
using namespace std;
template<typename T>
inline void read(T &sss){
	sss=0;char ccc=getchar();bool ooo=0;
	for(;!isdigit(ccc);ccc=getchar())
		if(ccc=='-') ooo=1;
	for(;isdigit(ccc);ccc=getchar())
		sss=sss*10+ccc-'0';
	sss=ooo?-sss:sss;
	return ;
}
const ll N=2e6+10;
ll c,t,n;
ll to[N],f[N][2];
ll d,x[N],cnt;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	read(c),read(t);
	while(t--){
		ll ans=0;
		read(n),read(d);
		for(ll i=1;i<=n;i++)
			read(x[i]);
		cnt=0;
		for(ll i=1;i<=n;i++){
			cnt=max(cnt,i);
			while(cnt<n&&x[cnt+1]-x[i]<=d)
				cnt++;
			to[i]=cnt;}
		for(ll i=n;i>=1;i--){
			ll u=to[i];
			f[i][0]=f[i][1]=0;
			if(u==i)
				continue;
			f[i][0]=u-i;
			if(to[u]!=to[u-1])
				f[i][0]+=f[u][0],f[i][1]+=f[u][1];
			if(u-2>=i)
			f[i][1]=to[u-1]-((u-2==i)? u:to[u-2]);
			if(u-2>=i&&to[u]!=u&&to[u]==to[u-1]&&(to[u]!=to[u-2]||u-2==i))
				f[i][1]+=f[u][0]-max(0ll,to[u-1]-u);
			ans+=f[i][1];
			}
		printf("%lld\n",ans);
	}
	return 0;
} 

#include<bits/stdc++.h>
#define N 2000010
using namespace std;
typedef long long ll;
const ll INF=0x3f3f3f3f3f3f3f3f;
int c,T,n;
ll d,a[N];
namespace Brute{
	ll f[N],g[N],pre[N],ans;
	void solve(){
		ans=0;
		for(int i=1;i<=n;++i){
			f[i]=0, g[i]=1; pre[i-1]=0, pre[i]=1;
			int p=i,q=i;
			for(int j=i+1;j<=n;++j){
				f[j]=INF, g[j]=0;
				while(p<=j && a[j]-a[p]>d) ++p;
				if(p==j) break;
				while(q<p || f[q]==f[p]) ++q;
				f[j]=f[p]+1; g[j]=pre[q-1]-pre[p-1];
				pre[j]=pre[j-1]+g[j];
				if(g[j]==2) ++ans;
			}
		}
		printf("%lld\n",ans);
	}
}
namespace SubtaskA{
	void solve(){
		if(a[2]-a[1]>d) { puts("0"); return ; }
		if(a[2]-a[1]==d) { puts("0"); return ; }
		int len=0;
		for(int i=2;i<=n;++i)
			if(a[i]-a[1]<=d) ++len;
		len<<=1; if(len>n) { puts("0"); return ; }
		printf("%d\n",n-len+1);
	}
}
namespace SubtaskB{
	int nxt[N];
	void solve(){
		int p=1;
		for(int i=1;i<=n;++i){
			while(p<=n && a[p]-a[i]<=d) ++p;
			nxt[i]=p-1;
		}
		p=0;
		for(int i=1;i<=n;++i){
			if(a[i]-a[1]<=d && a[n]-a[i]<=d){
				p=i; break;
			}
		}
		ll ans=0;
		for(int i=1;i<p;++i){
			if(nxt[i]==p+1) ans+=nxt[p]-nxt[p-1];
		}
		printf("%lld\n",ans);
	}
}
void work(){
	scanf("%d%lld",&n,&d);
	for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
	if(c<=10) Brute::solve();
	else if(c==11 || c==12) SubtaskA::solve();
	else if(c==13 || c==14) SubtaskB::solve();
	else Brute::solve();
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--) work();
	return 0;
}

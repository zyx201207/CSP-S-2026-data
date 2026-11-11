#include<bits/stdc++.h>
using namespace std;
namespace cs{
	#define LL long long
	#define fir first
	#define sec second
	typedef pair<int,int> PII;
	const int N=2e6;
	const int INF=2e9;
	int Case,T,n,pre[N+5],nxt[N+5];
	LL d,pos[N+5];
	int ps[N+5],ss[N+5],f[N+5],g[N+5];
	LL ans;
	void Init(){
		for(int i=1;i<=n;i++){
			f[i]=g[i]=0;
		}
		ans=0;
	}
	int main(){
		ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
		freopen("migrate.in","r",stdin);
		freopen("migrate.out","w",stdout);
		cin>>Case>>T;
		while(T--){
			Init();
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>pos[i];
			}
			for(int i=1,pt=1;i<=n;i++){
				while(pt<n&&pos[pt+1]-pos[i]<=d) pt++;
				nxt[i]=pt;
				if(nxt[i]!=i) f[nxt[i]]++;
			}
			for(int i=n,pt=n;i>=1;i--){
				while(pt>1&&pos[i]-pos[pt-1]<=d) pt--;
				pre[i]=pt;
				if(pre[i]!=i) g[pre[i]]++;
			}
			for(int i=1;i<=n;i++){
				ps[i]=f[i];
				if(pre[i]==i) continue;
				if(nxt[pre[i]]==i) ps[i]+=ps[pre[i]];
			}
			for(int i=n;i>=1;i--){
				ss[i]=g[i];
				if(nxt[i]==i) continue;
				if(pre[nxt[i]]==i) ss[i]+=ss[nxt[i]];
			}
			for(int i=2;i<=n;i++){
				ans+=f[i]*1ll*g[i-1];
				if(nxt[i-1]==i&&pre[i]==i-1) ans--;
			}
//			for(int i=1;i<=n;i++){
//				printf("i:%d pre:%d nxt:%d f:%d g:%d ps:%d ss:%d\n",i,pre[i],nxt[i],f[i],g[i],ps[i],ss[i]);
//			}
			for(int i=1;i<=n;i++){
				if(nxt[i]==i||nxt[nxt[i]]==nxt[i]) continue;
				if(pre[nxt[nxt[i]]]==nxt[i]-1) ans+=ss[nxt[nxt[i]]];
			}
			for(int i=n;i>=1;i--){
				if(pre[i]==i||pre[pre[i]]==pre[i]) continue;
				if(nxt[pre[pre[i]]]==pre[i]+1) ans+=ps[pre[pre[i]]];
			}
			for(int i=1;i<=n;i++){
				if(nxt[i]==i||nxt[nxt[i]]==nxt[i]) continue;
				if(pre[nxt[nxt[i]]]!=nxt[i]-1) continue;
				if(pre[nxt[i]-1]!=i) continue;
				ans+=ps[i]*1ll*ss[nxt[nxt[i]]];
			}
			cout<<ans<<"\n";
		}
		return 0;
	}
}
int main(){
	cs::main();
	return 0;
}
//17:04 Solve T3
//17:08 Comp T3 50500

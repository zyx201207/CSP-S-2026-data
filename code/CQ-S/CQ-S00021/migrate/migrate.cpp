#include<bits/stdc++.h>
using namespace std;
namespace air{
	int c,t,n;
	long long d,x[2000005];
	int hd[1000005],nxt[2000005],to[2000005],cnt;
	void add(int u,int v){
		nxt[++cnt]=hd[u];
		hd[u]=cnt;
		to[cnt]=v;
	}
	bool vst[1000005];
	int dst[1000005],f[1000005];
	int dl[1000005],l,r;
	void bfs(int s){
		for(int i=1;i<=n;i++){
			vst[i]=0;
			dst[i]=0;
			f[i]=0;
		}
		l=0,r=-1;
		f[s]=1;
		dl[++r]=s;
		while(l<=r){
			int u=dl[l++];
			for(int i=hd[u];i;i=nxt[i]){
				int v=to[i];
				if(!vst[v]){
					vst[v]=1;
					dst[v]=dst[u]+1;
					dl[++r]=v;
					f[v]=f[u];
				}
				else if(dst[v]==dst[u]+1){
					f[v]+=f[u];
				}
			}
		}
	}
	int main(){
		cin>>c>>t;
		while(t--){
			cnt=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
				hd[i]=0;
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(x[j]-x[i]<=d)add(i,j);
				}
			}
			int ans=0;
			for(int i=1;i<=n;i++){
				bfs(i);
				for(int j=i+1;j<=n;j++){
					if(f[j]==2)ans++;
				}
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	air::main();
	return 0;
}

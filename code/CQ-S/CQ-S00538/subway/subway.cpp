#include<bits/stdc++.h>
using namespace std;
bool OP;
namespace cs{
	#define LL long long
	#define fir first
	#define sec second
	typedef pair<int,int> PII;
	const int N=500;
	const int M=5e5;
	const LL INF=1e18;
	int Case,n,m,d,Q,k;
	LL w[M+5];
	int to[M+5][25],size[M+5];
	LL val[M+5][25];
	LL dist[N+5][N+5],ans;
	inline void updmin(LL& x,LL y){if(x>y) x=y;}
	int main(){
		ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
		freopen("subway.in","r",stdin);
		freopen("subway.out","w",stdout);
		cin>>Case>>n>>m>>d>>Q;
		for(int i=1;i<=m;i++){
			cin>>w[i];
		}
		int x,y;
		for(int i=1;i<=n;i++){
			cin>>k;
			for(int j=1;j<=k;j++){
				cin>>x>>y;
				++size[x];
				to[x][size[x]]=i;
				val[x][size[x]]=y;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dist[i][j]=INF;
			}
			dist[i][i]=0;
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=size[i];j++){
				for(int l=1;l<=size[i];l++){
					updmin(dist[to[i][j]][to[i][l]],val[i][j]+val[i][l]);
				}
			}
		}
		for(int l=1;l<=n;l++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					updmin(dist[i][j],dist[i][l]+dist[l][j]);
				}
			}
		}
		while(Q--){
			ans=INF;
			cin>>x>>y;
			for(int i=1;i<=size[x];i++){
				for(int j=1;j<=size[y];j++){
					updmin(ans,val[x][i]+dist[to[x][i]][to[y][j]]+val[y][j]);
				}
			}
			ans+=w[x]+w[y];
			cout<<ans<<"\n";
		}
		return 0;
	}
}
bool ED;
int main(){
	cs::main();
	cerr<<"Memory:"<<abs(&OP-&ED)/1000.0/1000<<"MB\n";
	return 0;
}
//14:55 Solve T2

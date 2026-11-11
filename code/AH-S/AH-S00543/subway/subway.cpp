#include<iostream>
#include<vector>
using namespace std;
const int MAXN=5e5+7;
struct xp{
	int a,t;
}g[502][MAXN];
int c,n,m,d,q;
int w[MAXN];
vector<int> e[502];
bool vis[502];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>g[i][j].a>>g[i][j].t;
		}
	}
	for(int i=0;i<502;i++) vis[i]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=g[i].size();i++){
			if(j==1) e[g[i][j]].push_back(g[i][j+1]);
			else if(j==g[i].size()) e[g[i][j]].push_back(g[i][j-1]);
			else{
				e[g[i][j]].push_back(g[i][j+1]);
				e[g[i][j]].push_back(g[i][j-1]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		long long ans=w[x]+w[y];
		cout<<ans<<endl;
	}
	return 0;
}

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=505;
int n,m,c,d,q;
vector<int> anss;
vector<pair<int,int> > g[maxn];
int k[maxn];
bool cmp(pair<int,int> ss1,pair<int,int> ss2){
	return ss1.first>ss2.first;
}
int jls[1011][1011];
bool fw[1011][1011];
int w[500011];
void dfs(int uu,int vv){
//	cout<<"found"<<uu<<" "<<vv<<"\n";
	fw[uu][vv]=fw[vv][uu]=true;
	for(int i=1;i<=m;i++){
		if(i!=uu&&jls[i][uu]>=1e15&&(!fw[i][uu])) dfs(i,uu);
		if(vv!=i&&jls[i][vv]>=1e15&&(!fw[i][vv])) dfs(i,vv);
		if(i!=uu&&i!=vv){
			jls[uu][vv]=jls[vv][uu]=min(jls[uu][vv],jls[i][uu]+jls[i][vv]);
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int ti,gos;
			cin>>gos>>ti;
			g[i].push_back({gos,ti});
		}
		//sort(g[i].begin(),g[i].end(),cmp);
	}
	if(c<=11){
		memset(jls,0x3f,sizeof(jls));
		for(int i=1;i<=m;i++){
			for(int j=0;j<k[i];j++){
				for(int vs=j+1;vs<k[i];vs++){
					int go1=g[i][j].first,go2=g[i][vs].first;
					jls[go1][go2]=jls[go2][go1]=min(jls[go2][go1],g[i][j].second+g[i][vs].second);
				}
			}
		}
		/*cout<<"\n";
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++) {
				if(jls[i][j]>=1e15) cout<<"n ";
				else cout<<jls[i][j]<<" ";
			}
			cout<<"\n"; 
		}
		cout<<"\n";*/
		while(q--){
			int u,v;
			cin>>u>>v;
			if(jls[u][v]>=1e15) dfs(u,v);
			cout<<jls[u][v]+w[u]+w[v]<<"\n";
		}
	}
	
}  

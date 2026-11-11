#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,tim[500005],in[500005],minn,loi=999999999999;
struct node{
	int ti,li;
};
vector<node> ve[500005];
vector<int> transfer[500005];
bool vis[505];
int find(int v,int w){
	int can=0;
	if(ve[v][0].li==ve[w][0].li||d==1) return ve[v][0].ti+ve[w][0].ti;
	else return 0;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>tim[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			ve[a].push_back({t,i});
			if(in[a]==0) in[a]=i;
			else if(transfer[a].empty()){
				transfer[a].push_back(in[a]);
				transfer[a].push_back(i);
			}
			else transfer[a].push_back(i);
		}
	}
	if(n==2){
		for(int i=1;i<=m;i++){
			if(transfer[i].size()) loi=min(loi,ve[i][0].ti+ve[i][1].ti);
		}
	}
	for(int i=1;i<=q;i++){
		int v,w;
		cin>>v>>w;
		if(ve[v][0].li==ve[w][0].li){
			cout<<tim[v]+tim[w]+ve[v][0].ti+ve[w][0].ti<<"\n";
			continue;
		}
		else if(n==2){
			cout<<tim[v]+tim[w]+ve[v][0].ti+ve[w][0].ti+loi<<"\n";
			continue;
		}
		memset(vis,0,sizeof(vis));
		cout<<find(v,w)+tim[v]+tim[w]<<"\n";
	}
}

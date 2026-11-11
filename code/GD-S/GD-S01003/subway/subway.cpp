#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
struct node{
	int to,cost;
};
vector<node> ve[500005];
bool vis[500005];
int dfs(int s,int t,int res){
	if(s==t){
		return res;
	}
	for(int i=0;i<ve[s].size();i++){
		if(!vis[ve[s][i].to]){
			vis[ve[s][i].to]=1;
			dfs(ve[s][i].to,t,res+ve[s][i].cost);
		}
	}
	return 0;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			ve[i].push_back({x,y});
		}
	}
	while(q--){
		int s,t;
		cin>>s>>t;
		cout<<dfs(s,t,0)<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

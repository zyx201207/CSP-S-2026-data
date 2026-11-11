#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q;
int w[500050],k[550],a[550][50005],t[550][50005];
int xi,yi;
int ans;
vector <int> g[50005];
void dfs(int id,int sum){
	if(id==yi){
		if(sum>ans){
			ans=sum;
		}
	}
	for(int i=0;i<g[id].size();i++){
		for(int j=0;j<k[g[id][i]];j++){
			int gm=a[g[id][i]][j];
			dfs(gm,sum+t[i][id]+t[i][gm]);
		}
	}
}

int main(){
//	freopen("subway.in","w",stdout);
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			g[a[i][j]].push_back(i);
		}
	}
	while(q--){
		cin>>xi>>yi;
		dfs(xi,w[xi]);
		ans+=yi;
		cout<<ans<<endl;
	}
	return 0;
}
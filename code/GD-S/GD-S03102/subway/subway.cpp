#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[510000];
vector<int>line[510000];
int x;
vector<pair<int,int> >s[510000];
void dfs(int id,int li,int sum){
	int xx=1;
	for(int i=0;i<line[line].size();i++){
		if()
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1,x;i<=n;i++){
		cin>>x;
		for(int j=1,y,t;j<=x;j++){
			cin>>y>>t;
			line[i].push_back({y,t});
		}
	}
	for(int i=1;i<=q;i++){
		int minn=1e9;
		cin>>x>>y;
		for(int j=1;j<=n;j++){
			dfs(x,j,w[x]);
		}
	}
	return 0;
}

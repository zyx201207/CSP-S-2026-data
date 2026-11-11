#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,t,w[505],flag[500005],fl[500005],fd[500005];
vector<pair<int,int>> q1[500005],q2[500005];
int dfs(int x,int find){
	int minnum=0x3f3f3f3f;
	if(x==find){
		return 0;
	}
	for(pair<int,int> r:q1[x]){
		if(fl[r.first]) continue;
		fl[r.first]=1;
		for(pair<int,int> y:q2[r.first]){
			if(fd[y.first]) continue;
			fd[y.first]=1;
			minnum=min(dfs(y.first,find)+r.second+y.second,minnum);
			fd[y.first]=0;
		}
		fl[r.first]=0;
	}
	return minnum;
}
int main(){
	cin>>c>>n>>m>>d>>t;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
	
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			fd[x]=true;
			q1[x].push_back({i,y});//点->线 
			q2[i].push_back({x,y});//线->点 
			fd[x]=false;
		}
	}
	while(t--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+dfs(x,y)+w[y]<<'\n';
	}
	return 0;
}

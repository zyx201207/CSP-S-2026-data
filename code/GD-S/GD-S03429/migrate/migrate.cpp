#include<bits/stdc++.h>//±©Á¦ 
using namespace std;
vector<int> cd;
void dfs(int x,int y,vector<int> gg[],int step{
	if(x==y){
		cd.push_back(step);
		return;
	}
	for(auto v:gg[x]){
		dfs(v,y,gg,step+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		int n,d;
		cin>>n>>d;
		vector<long long> v(n+5,0);
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
			v[i]=x;
		}
		vector<int> g[n+5];
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs(v[j]-v[i])<=d){
					g[i].push_back(j);
				}
			}
		}
		int ans=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				dfs(i,j,g,0);
				int ttt=INT_MAX;
				int cntt=0;
				for(auto u:cd){
					ttt=min(ttt,u);
				}
				for(auto u:cd){
					if(u==ttt) cntt++;
				}
				if(cntt==2){
					ans++;
					cntt=0;
				}
				else cntt=0;
			}
		}
		cout<<ans;
	}
	return 0;
}

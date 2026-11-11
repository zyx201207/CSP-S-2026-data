#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,p,w[500010],ans;
struct node{
	long long x,t;
}a[500010];
vector<node>g[500010];
void dfs(int y,int z,long long sum){
	if(y==z){
		ans=max(ans,sum);
		return;
	}
	if(ans<=sum)return;
	int l=g[y].size();
	for(int i=0;i<l;i++){
		if(g[y][i].x!=y){
			dfs(g[y][i].x,z,sum+g[y][i].t);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int j=1;j<=n;j++){
		int k;
		cin>>k;
		for(int i=1;i<=k;i++){
			cin>>a[i].x;
			cin>>a[a[i].x].t;
		}
		for(int i=1;i<k;i++){
			for(int l=i+1;l<=k;l++){
				g[a[i].x].push_back({a[l].x,a[a[i].x].t+a[a[l].x].t});
				g[a[l].x].push_back({a[i].x,a[a[i].x].t+a[a[l].x].t});
			}
		}
	}
	while(p--){
		int y,z;
		cin>>y>>z;
		dfs(y,z,(long long)0);
		cout<<ans+w[y]+w[z]<<endl;
		ans=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

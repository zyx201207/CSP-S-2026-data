#include<bits/stdc++.h>
using namespace std;
const int N=500+10,M=5e5+10;
long long c,n,m,d,p;
int a[N][N],w[M];
map<int,int>t[N];
long long dis[N][N];
vector<int> fa[M];
struct node{
	int ne;
	long long lo;
};
vector<node> ro[N];
void init(){
	for(int i = 1;i<=n;i++){
		for(auto it:ro[i]){
			dis[i][it.ne]=min(dis[i][it.ne],it.lo);
		}
	}
	for(int j = 1;j<=n;j++){
		for(int i = 1;i<=n;i++){
			for(int k = 1;k<=n;k++){
				if(i==k||j==k)continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	return ;
}

long long go(int x,int y){
	long long ans=w[x]+w[y];
	long long ji=INT_MAX;
	ji*=INT_MAX;
	for(auto it:fa[x]){
		for(auto th:fa[y]){
			ji = min(dis[it][th]+t[it][x]+t[th][y],ji);
		}
	}
	return ji+ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>c>>p;
	for(int i = 1;i<=m;i++){
		cin>>w[i];
	}
	int k;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			if(i==j)dis[i][j]=0;
			else{
				dis[i][j]=INT_MAX;
				dis[i][j]*=INT_MAX;
				dis[j][i]=dis[i][j];
			}
		}
	}
	for(int i = 1;i<=n;i++){
		cin>>k;
		for(int j = 1;j<=k;j++){
			cin>>a[i][j];
			cin>>t[i][a[i][j]];
			for(auto it:fa[a[i][j]]){
				ro[i].push_back({it,t[it][a[i][j]]+t[i][a[i][j]]});
				ro[it].push_back({i,t[it][a[i][j]]+t[i][a[i][j]]});
			}
			fa[a[i][j]].push_back(i);
		}
	}
	long long x,y;
	init();
	
	while(p--){
		cin>>x>>y;
		cout<<go(x,y)<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

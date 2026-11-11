#include <bits/stdc++.h>
using namespace std;

const int N	 = 505;
const int M = 5e5+5;
#define int long long
int c,n,m,d,q;
int w[M];
int a[N][5005],t[N][5005];
int ans=0;
vector<int> ve[M];
bool vis[M];
void dfs(int x,int y,int c){
	if(x==y)ans=max(ans,t[1][1]*c);
	for(auto z:ve[x]){
		if(!vis[z]){
			vis[z]=1;
			dfs(z,y,c+1);
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;//分别表示测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数。
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
		for(int j=1;j<k;j++){
			ve[a[i][j]].push_back(a[i][j+1]);
			ve[a[i][j+1]].push_back(a[i][j]);
		}
	}
	for(int i=1;i<=m;i++){
		
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		vis[x]=1;
		dfs(x,y,0);
		cout<<w[x]+w[y]+t[1][1]*2+ans;
	}
	return 0;
} 
//1<=n<=500,1<=m<=5e5+5

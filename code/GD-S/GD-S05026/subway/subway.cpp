#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int c,n,m,d,q,k;
long long ans;
int w[N],a[510][N],t[510][N];
bool dp[510];
vector<int> xl[510];
struct met{
	int dt[21];
	int n;
};
met dt[N];
void dfs(int x,int y){
	ans+=w[x]+w[y];
	for(int i=1;i<=dt[x].n;i++){
		xl[dt[x].dt[i]][1]; 
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			dt[j].dt[++dt[j].n]=i;	
		}
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			for(int k=1;k<=dt[a[i][j]].n;k++){
				if(dt[a[i][j]].dt[j]!=i){
					xl[i].push_back(dt[a[i][j]].dt[j]);
					xl[dt[a[i][j]].dt[j]].push_back(i);
				}
			}
		} 
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		dfs(x,y);
	}
	return 0;
}


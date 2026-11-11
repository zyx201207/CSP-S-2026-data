//#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<iomanip>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<ctime>
#include<deque>
#include<queue>
#include<stack>
#include<list>
using namespace std;
typedef long long ll;
constexpr const int N=500,M=5e5;
constexpr const ll inf=0x3f3f3f3f3f3f3f3f;
int n,m,d,w[M+1],k[N+1];
vector<int>a[N+1],t[N+1];
vector<pair<int,int>>g[N+1],id[M+1];
ll dis[N+1][N+1];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int cid,q;
	cin>>cid>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].resize(k[i]+1);
		t[i].resize(k[i]+1);
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			id[a[i][j]].push_back({i,t[i][j]});
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int x=1;x<=m;x++){
		for(auto [u,wu]:id[x]){
			for(auto [v,wv]:id[x]){
				if(u==v){
					dis[u][v]=0;
					continue;
				}
				dis[u][v]=wu+wv;
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans=inf;
		for(auto [u,wu]:id[x]){
			for(auto [v,wv]:id[y]){
				ans=min(ans,w[x]+wu+dis[u][v]+wv+w[y]);
			}
		}
		cout<<ans<<'\n';
	}
	
	cout.flush();
	
	/*fclose(stdin);
	fclose(stdout);*/
	return 0;
}

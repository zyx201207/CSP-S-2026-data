#include <bits/stdc++.h>
#define ll long long
using namespace std;
int c,y,ans,n;
unordered_map<int,int> hx[505];
int t[505][505],a[505][505];
bool vis[505][505];
int k[505];

void dfs(int u,int d,int i){
	if(u==y){
		ans=min(ans,d);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!hx[i][u]) continue;
		for(int j=1;j<=k[i];j++){
		int v=a[i][j];
		int u_id=hx[i][u];
		if(v!=u && vis[i][j]) continue;
		    vis[i][v]=1;
			dfs(v,d+t[i][u_id]+t[i][j],i);
			vis[i][v]=0;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >>c;
		int m,d,q;
		cin >>n >>m >>d >>q;
		vector<int> w(m+1);
		for(int i=1;i<=m;i++) cin >>w[i];
		for(int i=1;i<=n;i++){
			cin >>k[i];
			for(int j=1;j<=k[i];j++){
			    cin >>a[i][j];
			    cin >>t[i][j];
			    hx[i][a[i][j]]=j;
			} 
		}
		while(q--){
			int x;
			cin >>x >>y;
			dfs(x,0,0);
			/*
			priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; 
			pq.push({0,x,i});
            bool vi[505][505];
            vi[1][x]=1;
            vi[2][x]=1;
			while(!pq.empty()){
				int d=pq.top().first,u=pq.top().second;
				pq.pop();
				if(u==y){
					ans=d;
					break;
				}
				for(int i=1;i<=n;i++){
					if(!hx[i][u]) continue;
					for(int j=1;j<=k[i];j++){
			            int v=a[i][j];
			            int u_id=hx[i][u];
						if(v!=u && vi[i][j]) continue;
						pq.push({d+t[i][u_id]+t[i][j],v,i});
						vi[i][j]=1;
					}
				}
			}*/
			cout <<ans+w[x]+w[y] <<"\n";
		}
		return 0;
}

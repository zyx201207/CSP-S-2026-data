#include<bits/stdc++.h>
#define int long long
using namespace std;
int op1,op2,n,m,q,w[500005],k[505],a[505][505],t[505][505],dis[500005];
bool bj[500005];
vector<pair<int,int>> e[500005];
main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>op1>>n>>m>>op2>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1,sx;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			e[a[i][j]].push_back({i,j});
		}
	}
	while(q--){
		queue<int> q;
		memset(dis,0x3f,sizeof dis);
		memset(bj,0,sizeof bj);
		int x,y;
		cin>>x>>y;
		q.push(x);
		bj[x]=1;
		dis[x]=0;
		while(q.empty()==0){
			int u=q.front();
			q.pop();
			bj[u]=0;
			for(auto i:e[u]){
				for(int j=1;j<=k[i.first];j++){
					if(dis[a[i.first][j]]>dis[u]+t[i.first][i.second]+t[i.first][j]){
						dis[a[i.first][j]]=dis[u]+t[i.first][i.second]+t[i.first][j];
						if(bj[a[i.first][j]]==0){
							bj[a[i.first][j]]=1;
							q.push(a[i.first][j]);
						}
					}
				}
			}
		}
		cout<<dis[y]+w[x]+w[y]<<"\n";
	}
	return 0;
}

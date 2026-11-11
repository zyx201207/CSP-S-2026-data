#include<bits/stdc++.h>
#define tin long long
using namespace std;
tin c,n,m,d,qus,w[500005],wal[505][505];
vector<pair<tin,tin> > vec[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>qus;
	for(tin i=1;i<=m;i++) cin>>w[i];
	for(tin i=1;i<=n;i++){
		tin k;cin>>k;
		for(tin j=1;j<=k;j++){
			tin a,t;cin>>a>>t;
			vec[a].push_back({i,t});
		}
	}memset(wal,0x3f,sizeof(wal));
	for(tin i=1;i<=n;i++) wal[i][i]=0;
	for(tin x=1;x<=m;x++){
		tin k=vec[x].size();
		for(tin i=0;i<k;i++)
			for(tin j=i+1;j<k;j++){
				pair<tin,tin> u=vec[x][i],v=vec[x][j];
				wal[u.first][v.first]=min(wal[u.first][v.first],u.second+v.second);
				wal[v.first][u.first]=min(wal[v.first][u.first],v.second+u.second);
			}
	}
	for(tin k=1;k<=n;k++)
		for(tin i=1;i<=n;i++)
			for(tin j=1;j<=n;j++){
				tin u=i,v=j;
				if(u!=v&&wal[u][v]>wal[u][k]+wal[k][v])
					wal[u][v]=wal[v][u]=wal[u][k]+wal[k][v];
			}
	while(qus--){
		tin x,y,ans=1e18;cin>>x>>y;
		for(tin i=0;i<vec[x].size();i++)
			for(tin j=0;j<vec[y].size();j++){
				pair<tin,tin> u=vec[x][i],v=vec[y][j];
				ans=min(ans,wal[u.first][v.first]+u.second+v.second);
			}
		ans+=w[x]+w[y];
		cout<<ans<<"\n";
	}
	return 0;
}

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=5e5+5,N=505,INF=19191919191919810;
int c,n,m,d,q,w[M],k,ia,it,mp[N][N],x,y;
vector<int>t[M],v[M];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j)mp[i][j]=INF;
	for(int i=1;i<=n;i++){
		cin>>k;
		while(k--){
			cin>>ia>>it;
			for(int j=0;j<t[ia].size();j++){
				int ft=t[ia][j],fv=v[ia][j];
				mp[ft][i]=mp[i][ft]=min(mp[ft][i],it+fv);
			}
			t[ia].push_back(i);
			v[ia].push_back(it);
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)for(int k=1;k<=n;k++)mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
	while(q--){
		cin>>x>>y;
		int s=INF;
		for(int i=0;i<t[x].size();i++)for(int j=0;j<t[y].size();j++)s=min(s,v[x][i]+v[y][j]+mp[t[x][i]][t[y][j]]);
		cout<<s+w[x]+w[y]<<'\n';
	} 
	return 0;
}//Please! Run!

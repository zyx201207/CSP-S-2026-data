#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
int c,n,m,d,q;
int w[500005];
int a,t;
int k[505];
vector<pii>g[505];
vector<pii>xian[500005];
int f[505][505];
int x,y;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a>>t;
			g[i].push_back({a,t});
			xian[a].push_back({i,t});
		}
	}
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int i=1;i<=m;i++){
		//cout<<i<<endl; 
		for(pii j:xian[i]){
			for(pii k:xian[i]){
				//cout<<j.first<<" "<<k.first<<endl;
				f[j.first][k.first]=
				min(f[j.first][k.first],j.second+k.second);
				f[k.first][j.first]=f[j.first][k.first];
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(!f[i][j]||!f[i][k]||!f[j][k])continue;
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<f[i][j]<<" ";
//		}cout<<endl;
//	}
	int ans=0;
	while(q--){
		cin>>x>>y;
		ans=1e18;
		for(pii i:xian[x]){
			for(pii j:xian[y]){
				ans=min(ans,i.second+j.second+f[i.first][j.first]);
			}
		}cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2


*/




#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+10;
int c,t,x[N];
pair<int,int> f[N][N];
void slv(){
	int n,d;
	int ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++) f[i][j]=make_pair(INT_MAX,0);
	for(int i=1;i<=n;i++) cin>>x[i],f[i][i]={1,1};
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			pair<int,int> yuy=make_pair(INT_MAX,0);
			for(int y=j;y>=i;y--){
				if(x[j]-x[y]>d) break;
				if(yuy.first>=f[i][y].first+1){
					if(yuy.first>f[i][y].first+1) yuy.first=f[i][y].first+1,yuy.second=f[i][y].second;
					else yuy.second+=f[i][y].second;
				}
			}
			f[i][j]=yuy;
		}
		for(int j=1;j<=n;j++){
			if(f[i][j].second==2) ans++;
		}
		//for(int ui=i;ui<=n;ui++){for(int j=i;j<=n;j++)cout<<'('<<f[i][j].first<<','<<f[i][j].second<<") ";cout<<'\n';}
	}
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) slv();
	return 0;
}

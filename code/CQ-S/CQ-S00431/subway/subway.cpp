#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
const int N=505,M=5e5+5,MX=(1e18);
int f[N][N];
int a[M];
int s[N];
vector<int>e[M],t[M];
int ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>s[i];
		for(int j=1;j<=s[i];j++){
			int x,y;cin>>x>>y;
			e[x].push_back(i);
			t[x].push_back(y);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j)f[i][j]=MX;
			else f[i][j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<e[i].size();j++){
			for(int k=j+1;k<e[i].size();k++){
				int x=e[i][j],y=e[i][k];
				f[x][y]=f[y][x]=min(f[x][y],t[i][j]+t[i][k]);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
			}
		}
	}
	for(int ii=1;ii<=q;ii++){
		int x,y;
		cin>>x>>y;
		ans=MX;
		for(int i=0;i<e[x].size();i++){
			for(int j=0;j<e[y].size();j++){
				int xx=e[x][i],yy=e[y][j];
				int val=a[x]+a[y]+t[x][i]+t[y][j];
				ans=min(ans,f[xx][yy]+val);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

#include<iostream>
#include<vector>
#define int long long
using namespace std;
vector<pair<int,int> > g[500005];
int cb[500005];
int f[505][505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=5e12;
			if(i==j)f[i][j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>cb[i];
	}for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			g[a].push_back((pair<int,int>){i,t});
		}
	}for(int i=1;i<=m;i++){
		for(int k=0;k<(long long)g[i].size();k++){
			for(int j=0;j<(long long)g[i].size();j++){
				if(j==k or g[i][j]==g[i][k]){
					continue;
				}pair<int,int> l=g[i][j];
				pair<int,int> r=g[i][k];
				f[l.first][r.first]=min(f[l.first][r.first],l.second+r.second);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		int minn=5e12;
		for(auto j:g[x]){
			for(auto k:g[y]){
				minn=min(minn,j.second+k.second+f[j.first][k.first]);
			}
		}
		cout<<minn+cb[x]+cb[y]<<'\n';
	}
	return 0;
}
	

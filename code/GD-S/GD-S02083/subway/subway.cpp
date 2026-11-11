#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=5e5+10,M=505,inf=1e18;
struct node{
	int x,y;
}; 
int c,n,m,d,q,w[N],f[M][M];
vector<node> a[N]; 
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			a[x].push_back({i,y});
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) f[i][j]=inf;
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=m;i++){
		int l=a[i].size();
		for(int j=0;j<l;j++){
			for(int k=j+1;k<l;k++){
				int xj=a[i][j].x,xk=a[i][k].x,yj=a[i][j].y,yk=a[i][k].y;
				f[xj][xk]=f[xk][xj]=min(f[xj][xk],yj+yk);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j&&i!=k&&j!=k){
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				}
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=inf;
		for(int i=0;i<a[x].size();i++){
			for(int j=0;j<a[y].size();j++){
				int xx=a[x][i].x,xy=a[y][j].x;
				ans=min(ans,w[x]+w[y]+a[x][i].y+a[y][j].y+f[xx][xy]);
			}
		} 
		cout<<ans<<endl;
	}
	return 0;
}


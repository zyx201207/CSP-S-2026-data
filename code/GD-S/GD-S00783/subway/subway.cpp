#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=5e5+5;
const int N=505;
int c,n,m,d,q; 
int a[M],k[N];
vector<pair<int,int> >pas[M]; 
int trans[N][N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0); 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >>c >> n >> m >>d >> q;
	for(int i=1;i<=m;i++) cin >> a[i];
	for(int i=1;i<=n;i++){
		cin >> k[i];
		for(int j=1;j<=k[i];j++){
			int x,t;
			cin >> x >> t;
			pas[x].push_back({i,t});	
		} 
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j) trans[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<pas[i].size();j++){
			for(int k=0;k<pas[i].size();k++){
				if(j==k) continue;
				else trans[pas[i][j].first][pas[i][k].first]=min(trans[pas[i][j].first][pas[i][k].first],pas[i][j].second+pas[i][k].second);
			}
		} 
 	}
 	for(int k=1;k<=n;k++){
 		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j||j==k||i==k) continue;
				trans[i][j]=min(trans[i][j],trans[i][k]+trans[j][k]);
			}
		}
	} 
	for(int i=1;i<=q;i++){
		int x,y;
		cin >>x >> y;
		int ans=1e18;
		for(int j=0;j<pas[x].size();j++){
			for(int k=0;k<pas[y].size();k++){
				ans=min(ans,pas[x][j].second+pas[y][k].second+trans[pas[x][j].first][pas[y][k].first]);
			}
		} 
		ans+=a[x]+a[y];
		cout << ans <<endl;
	}
} 

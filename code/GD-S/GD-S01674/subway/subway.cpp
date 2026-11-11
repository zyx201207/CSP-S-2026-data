#include <bits/stdc++.h>
#define int long long
#define mk make_pair
using namespace std;
const int N=500005;
int n,m,c,d,q,w[N],f[505][505],a[25],t[25],a2[25],t2[25];
vector<pair<int,int> > b[N];
void Min(int &x,int y){
	x=x>y?y:x;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=1e18;
		}
		f[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			b[x].push_back(mk(i,y));
		}
	}
	for(int i=1;i<=m;i++){
		if(b[i].size()>=2){
			int k=b[i].size();
			for(int j=1;j<=k;j++){
				a[j]=b[i][j-1].first;
				t[j]=b[i][j-1].second;
			}
			for(int j=1;j<=k;j++){
				for(int l=1;l<=k;l++){
					Min(f[a[j]][a[l]],t[j]+t[l]);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
//	for(int i=n;i>=1;i--){
		for(int j=1;j<=n;j++){
//		for(int j=n;j>=1;j--){
//			for(int l=1;l<=n;l++){
			for(int l=n;l>=1;l--){
				Min(f[i][l],f[i][j]+f[j][l]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		int k=b[x].size();
		for(int j=1;j<=k;j++){
			a[j]=b[x][j-1].first;
			t[j]=b[x][j-1].second;
		}
		int k2=b[y].size();
		for(int j=1;j<=k2;j++){
			a2[j]=b[y][j-1].first;
			t2[j]=b[y][j-1].second;
		}
		int ans=1e18;
		for(int j=1;j<=k;j++){
			for(int l=1;l<=k2;l++){
				Min(ans,t[j]+f[a[j]][a2[l]]+t2[l]);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
}

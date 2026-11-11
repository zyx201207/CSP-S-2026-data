#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
const int N = 505;
const int M = 500005;
int w[M],k[N],a[N][M],t[N][M];
int x,y;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		cin>>x>>y;
		cout<<w[x]+w[y]+t[1][1]*2<<'\n';
	}
	return 0;
} 

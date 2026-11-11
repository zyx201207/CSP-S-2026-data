#include<bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;
const int N = 505;
const int M = 100005;
int c,n,m,d,q;
int w[N];
int k[N];
int a[N][N];
int t[N][N];
//int e[n<<2], net[n<<2], h[N<<2], v[N<<2];
//int cnt;
//void add(int u, int v, int z){
//	e[++cnt] = v;
//	nex[cnt] = h[x];
//	v[cnt] = z;
//	h[x] = cnt;
//}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);	cin.tie(0);	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1; i <= m; i++){
		cin>>w[i];
	}
	for(int i = 1; i <= n; i++){
		cin>>k[i];
		for(int j = 1; j <= k[i]; j++){
			cin>>a[i][j]>>t[i][j];
//			if(j!=1){
//				add(a[i][j-1], a[i][j]);
//				add(a[i][j], a[i][j-1]);
//			}
		}
	}
	while(q--){
		ll ans = 0;
		int x,y;
		cin>>x>>y;
		ans = w[x]+w[y];
		bool flag = false;
		for(int i = 1; i <= n; i++){
			if(t[i][x] != 0 && t[i][y] != 0){
				cout<<ans + t[i][x] + t[i][y]<<endl;
				flag = true;
				break;
			}
		}
		if(!flag){
			cout<<ans + t[1][x] + t[1][y]<<endl;
		}
	}
	
	return 0;
} 

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int w[N],t[505][N],dp[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i = 0;i < m;i++) cin>>w[i];
	for(int i = 0;i < n;i++){
		int k;
		cin>>k;
		for(int j = 0;j < k;j++){
			int a;
			cin>>a;
			else cin>>t[i][a];
		}
	}
	while(q--){
		int x,y,tmp = 0;
		int ans = w[x] + w[y];
		cin>>x>>y;
		while(x <= y){
			for(int i = 0;i < n;i++) tmp = max(tmp,t[i][x]);
			ans += tmp;
		}
		cout<<tmp<<endl;
	}
	return 0;
}

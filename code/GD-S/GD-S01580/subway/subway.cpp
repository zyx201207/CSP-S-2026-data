#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int N=505,M=5e5+5;
int c,n,m,d,q;
int w[M];
vector<int> g[N];
vector<int> v[M];
signed main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) cin>>w[i];
	int k;
	cin>>k;
	for(int i=1,a,t; i<=k; i++) {
		cin>>a>>t;
		g[i].push_back(a);
		g[a].push_back(i);

	}

	return 0;
}

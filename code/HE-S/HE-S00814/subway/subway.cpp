#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=501;
int c,n,m,d,q;
int w[N];
int t[N][N],a[N][N];
int sum=0;
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++)	cin>>w[i];
	for(int i=1; i<=n; i++) {
		int k;cin>>k;
		for(int j=1; j<=k; j++) {
			cin>>a[i][j]>>t[i][j];
			sum+=t[i][j];
		}
	}
	while(q--) {
		int x,y;cin>>x>>y;
		cout<<sum+w[x]+w[y];
	}
	return 0;
}
/*
0 3 7 20 2

8 3 6 1 7 2 9

3 1 4 2 5 5 100

1 2 5
4 5 100

3 2 6 3 1 7 2

2 3 7
6 1 2

4 3 2 5 100 4 6 6 7

3 5   4 6
2 100 6 7

1 6
2 3




*/

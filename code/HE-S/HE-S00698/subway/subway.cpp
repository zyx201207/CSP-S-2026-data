#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505,M=5e3+50;
int c,n,m,d,q;
ll ans,w[N],k[N],a[N][M],t[N][M];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++)cin>>w[i];
	for(int i=1; i<=n; i++) {
		cin>>k[i];
		for(int j=1; j<=k[i]; j++)cin>>a[i][j]>>t[i][j];
	}
	while(q--) {
		ll x,y;
		cin>>x>>y;
		if(x>y)swap(x,y);
		ans=w[x]+w[y];
		for(int i=x; i<y; i++) 
			for(int j=i; j<=k[i]; j++) 
				if(a[i][j]<=y)ans+=t[i][j];
		for(int i=x+1;i<y;i++)ans+=t[i][i];
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/

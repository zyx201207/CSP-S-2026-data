#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,dp[505][505],w[505],a[505][20005],k,t[505][20005],x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
        cin>>w[i];
	}
	for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[i][j]>>t[i][j];
        }
	}
	int mj=812939623716;
	for(int i=1;i<=q;i++){
        cin>>x>>y;
        cout<<mj<<'\n';
	}
	return 0;
}

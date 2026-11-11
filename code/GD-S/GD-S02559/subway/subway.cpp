#include <bits/stdc++.h>
using namespace std;
int n,m,q,c,d,w[505],k[505],a[505][505],t[505][505],ans;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","W",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++)cin>>a[i][j]>>t[i][j];
	}
	for(int i=1;i<=q;i++){
		int s,e;
		cin>>s>>e;
		cout<<ans<<endl;
	}
	return 0;
}

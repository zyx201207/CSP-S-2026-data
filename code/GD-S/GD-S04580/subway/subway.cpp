#include <bits/stdc++.h>
using namespace std;
int n,m,c,d,q,k,a,x,y;
long long w[500005],t[505][50005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++){
		cin>>w[i];
	}
	for (int i=1;i<=n;i++){
		cin>>k;
		for (int j=1;j<=k;j++){
			cin>>a;
			cin>>t[i][a];
		}
	}
	for (int i=1;i<=q;i++){
		cin>>x>>y;
		long long sum=w[x]+w[y];
		for (int i=1;i<=n;i++){
			sum+=t[i][x]+t[i][y];
		}
		cout<<sum<<endl;
	}
}

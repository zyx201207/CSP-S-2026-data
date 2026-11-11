#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],a,t,k,x,y;
int main()
{
	// 快读 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	// 主代码
	cin>>c>>n>>m>>d>>q;
	for (long long i = 1;i <= m;i++) cin>>w[i];
	for (long long i = 1;i <= n;i++)
	{
		cin>>k;
		for (long long j = 1;j <= 2 * k;j++)
		{
			if (j % 2 == 1) cin>>a;
			else cin>>t;
		}
	}
	for (long long i = 1;i <= q;i++)
	{
		cin>>x>>y;
		cout<<w[x] + w[y]<<'\n';
	} //可能有点难 
	return 0;
}
// 不会 

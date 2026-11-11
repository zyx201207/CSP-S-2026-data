#include <bits/stdc++.h>
using namespace std;
long long m,n,c,d,q,w[500005],k[505],x[100005],y[100005],t,u,sum;
struct nnn
{
	int id,t;
};
vector<nnn>a[505];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>t>>u;
			a[i].push_back({t,u});
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
	}
	if(c==20||c==21)
	{
		for(int i=1;i<=q;i++)
		{
			
		}
	}
	return 0;
}

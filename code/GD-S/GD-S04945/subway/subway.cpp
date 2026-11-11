#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10,M=510;
long long c,n,m,d,q,x,y;
long long w[N],k[M],a[N],t[N];
vector<int> p[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j=k[i];j++)
		{
			cin>>a[j]>>t[j];

		}
	}
	while(q--)
	{
		cin>>x>>y;
	}
	return 0;
}


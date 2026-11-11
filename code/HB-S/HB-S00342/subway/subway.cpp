#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[500005],k[500005],x[500005],y[500005];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i = 1;i<=n;i++)
	{
		cin>>k[1];
		for(int j =2;j<=k[1]*2+1;j++)
		{
			cin>>k[j];
		}
	}
	for(int i = 1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
	}
	for(int i = 1;i<=q;i++)
	{
		cout<<(w[i]+k[i]+x[i]+y[i])*2+d/(2*i)<<endl;
	}
	return 0;
}

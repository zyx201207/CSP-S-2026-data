#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[100005],zhan[5005][5005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for (int i=1;i<=m;i++)
    {
    	cin>>w[i];
	}
	for (int i=1;i<=n;i++)
	{
		int ge;
		cin>>ge;
		for (int k=1;k<=ge;k++)
		{
			int bian;
			cin>>bian>>zhan[i][bian];
		}
	}
	for (int i=1;i<=q;i++)
	{
		int r,c,zong=0;
		cin>>r>>c;
		zong+=w[r];
		zong+=w[c];
		for (int j=r;j<=c;j++)
		{
			for (int k=1;k<=n;k++)
			{
				zong+=zhan[k][j];
			}
		}
		cout<<zong;
	}
}

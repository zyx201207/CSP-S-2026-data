#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],x,y,gj,k,jg;
bool a[505][1005];
long long t[505][1005];
long long ques(long long x,long long y)
{
	long long dis=x,ans=0;
	ans+=w[x]+w[y];
	while(dis!=y)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i][dis]==1)
			{
				for(int j=1;j<=m;j++)
				{
					if(a[i][j]==1&&j!=dis)
					{
						ans+=t[i][j]+t[i][dis];
						dis=j;
						break;
					}
				}
				break;
			}
		}
	}
	return ans;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>gj;
			a[i][gj]=1;
			cin>>jg;
			t[i][gj]=jg;
		}
	}
	while(q--)
	{
		cin>>x>>y;
		if(x>y)
			cout<<ques(x,y)<<endl;
		else
			cout<<ques(y,x)<<endl;
	}
}

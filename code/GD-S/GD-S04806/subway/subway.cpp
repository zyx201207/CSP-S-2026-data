#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxs=5e5+4;
int c;
ll n,m,d,q,k,sum=0,w[maxs],t[503][maxs],a[503][maxs],k1[503],ft,ed;
bool e[503]={false};
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[maxs];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		k1[i]=k;
		for(int j=1;j<=k;j++)
		{
			cin>>a[i][j];
			cin>>t[i][a[i][j]];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>ft>>ed;
		sum=0;
		sum+=(w[ft]+w[ed]);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=k1[i];j++)
			{
				if(a[i][j]==ft)
				{
					
				}
			}
		}
	}
	return 0;
}

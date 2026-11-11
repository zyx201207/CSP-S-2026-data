#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1000000+7;
ll n,m;
int a[N],b[N];
ll d[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			d[i][j]=b[j];
			ll l=n;
			ll r=l;
			while(l>0)
			{
				if(d[r]==d[l])
			{
			for(int i=l;i<=r;i++)
			{
				d[i]=0;
			}
			
		}
	}
	ll cl=0;
	for(int y=1;y<=m;y++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(d[i][j]==m)
				{
					cl++;
				}	
			}
		}
		cout<<cl;
	}

	return 0;
}

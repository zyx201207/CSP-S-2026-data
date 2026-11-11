#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
typedef long long ll;
int a[N];
int b[N];
int c[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, cnt=0; 
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		memset(b,0,sizeof(b));
		cnt=0;
		for(int j=i;j<=n;j++)
		{
			bool f=0;
			for(int k=0;k<cnt;k++)
			{
				if(b[k]==a[j])
				{
					cnt=k;
					cnt++;
					f=1;
				}
			}
			if(f==0)
			{
				b[cnt]=a[j];
				cnt++;
			}
		}
		for(int j=0;j<cnt;j++)
		{
			c[b[j]]++;
		}
		memset(a,0,sizeof(a));
		for(int j=0;j<cnt;j++)
		{
			a[j]=b[j];
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<' ';
	}
	return 0;
}

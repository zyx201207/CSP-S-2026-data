#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int a[500007],b[500007];
int c[500007];
int check(int k,int x)
{
	for(int i=1;i<=k;i++)
	{
		if(c[i]==x)  return i;
	}
	return -1;
}
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout.tie(nullptr);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k=0;
		for(int j=i;j<=n;j++)
		{
			if(check(k,a[j])==-1) c[++k]=a[j];
			else
			{
				k=check(k,a[j]);
				c[k]=a[j]; 
			}
		}
		for(int j=1;j<=k;j++)
		{
			b[c[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<' ';
	}
	return 0;
}


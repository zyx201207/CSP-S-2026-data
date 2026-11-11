#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010],b[300010];
bool f[300010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	int tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		string s;
		s+=a[i];
		for(int j=i;j<=n;j++)
		{
			if(a[j]==s[i])
			{
				s[i]=a[j];
				f[i]==1;
			}
		}
		for(int j=1;j<=m;j++)
		{
			if(f[i]==1)
			{
				b[i]+=1;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
}

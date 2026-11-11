#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[10005],s[10005];
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		for(int j=0;j<i;j++)
		{
			if(a[j]==a[i])
			{
				for(int f=0;f<i;f++)
				{
					a[f]=0;
					s[i]++;
				}
			}
		}
	}
	for(int i=0;i<=n;i++)
	{
		cout<<s[i];
	}
	return 0;
}

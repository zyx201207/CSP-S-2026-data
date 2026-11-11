#include<bits/stdc++.h>
using namespace std;
int n,s,k,m,a[500010]; 
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m<=2)
	{
		if(a[n]==1)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==2)
				{
					s++;
				}
			}
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1)
				{
					s++;
				}
			}
		}
		cout<<s<<' '<<n;
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<n<<' ';
	}
	return 0;
}


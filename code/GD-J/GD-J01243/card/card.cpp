#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main()
{
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m == 1)
	{
		cout<<n;
		return 0;
	}
	int x=0;
	if(a[n]==1)
	{
		cout<<n<<" "; 
		for(int i = n ;i>=1;i--)
		{
			if(a[i]==2)
			{
				cout<<i;
				x = 1;
				return 0;
			}
		}
		if(x == 0) cout<<0;		
	}
	else if(a[n]==2)
	{		
		for(int i = n ;i>=1;i--)
		{
			if(a[i]==2)
			{
				cout<<i<<" ";
				x=1;
				break;
			}
		}
		if(x==0) cout<<0<<" ";
		cout<<n;
	}
	return 0;
 } 

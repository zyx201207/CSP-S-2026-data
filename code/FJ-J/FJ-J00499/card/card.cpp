#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[100000];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		cout<<n;
	}
	if(m==2)
	{
		if(a[1]==a[n])
		{
			cout<<n-2<<' '<<n;
		}
		else
		{
			cout<<n-1<<' '<<n;
		}	
	}
	return 0;
}

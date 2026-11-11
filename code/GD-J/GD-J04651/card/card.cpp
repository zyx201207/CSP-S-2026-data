#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[10005];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==2)
		{
			cout <<i<<" ";
		}
	}
	return 0;
}

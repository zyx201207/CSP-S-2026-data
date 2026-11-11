#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int b;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i] == a[j])b++;
		}
	}
	cout<<n - b;
	
	return 0;
}

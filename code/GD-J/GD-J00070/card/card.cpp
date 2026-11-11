#include <bits/stdc++.h>
using namespace std;
int main ()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[11];
	cin>>n>>m;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
	}
	srand(time(0));
	for(int i=1; i<=m; i++)
	{
		cout<<rand()%n+1;
	}
	return 0;
}

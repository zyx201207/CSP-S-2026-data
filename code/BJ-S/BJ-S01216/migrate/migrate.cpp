#include<bits/stdc++.h>
using namespace std;
int x,y,n,d,a[1000];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>x>>y;
	for(int i=0;i<=y;i++)
	{
		cin>>n>>d;
		for(int j=0;j<=n;j++)
		{
			cin>>a[i];
		}
		cout<<(n-1)/y;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

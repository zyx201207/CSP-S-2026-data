#include <bits/stdc++.h> 
using namespace std;
int a[500005];
int b[500005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int e=1;
	for(int i=1;i<=t;i++)
	{
		int num;
		cin>>num>>a[i];
		for(int j=e;j<=num;j++)
		{
			
			cin>>b[j];
		}
	}
	return 0;
}

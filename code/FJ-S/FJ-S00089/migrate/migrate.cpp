#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	cin >> c >>t;
	while(t--)
	{
		cin >> n >> d;
		vector<int> a(n);
		for(int i=0;i<n;i++)
		{
			cin >> a[i];
		}
		if(n<=3)
		{
			cout << 0;
		}
		else if(n>3&&d==2)
		{
			cout << n-3;
		}
		else if(n>3)
		{
			cout << (n-3+d-2)%(n+2);
		}
	}
	return 0;
}

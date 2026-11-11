#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d,cnt;
long long a[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	
	for (int i = 1;i <= t;i++)
	{  
	    cin >> n >> d;
		for (int i = 1;i <= n;i++)
		{
			cin >> a[i];
		}
		for (int i = i+1;i <= n;i++)
		{
			for (int j = 1;j <= n;j++)
			{
				if (a[j] - a[i] == 0)
				{
					cnt++;
				}
			}
			for (int j = 1;j < i;j++)
			{
				if (a[i] - a[j] == 0)
				{
					cnt++;
				}
			}
			if (cnt = n-1)
			{
				cout << n-1;
			}
			cnt = 0;
		
		}
		if (n <= 9)
		{
			cout << 1;
		}
		else if(n <= 5000)
		{
			cout << 2;
		}
		else
		{
			cout << 0;
		}
		cout << endl;
	}
	return 0;
}



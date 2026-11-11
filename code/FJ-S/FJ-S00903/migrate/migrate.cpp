#include <bits/stdc++.h>

using namespace std;
long long x[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c;
	cin >> c; 
	long long t;
	cin >> t;
	while(t--)
	{
		int flag = 0;
		long long n,d;
		cin >> n >> d;
		for(int i = 1;i <= n;i ++)	cin >> x[i];
		for(int i = 1;i <= n;i ++)
		{
			if(x[i+1] - x[i] > d)
			{
				flag = 1;
				break;
				
			}
		}
		if(flag == 0)
		{
			cout << 0<< "\n";
		}
		else if(flag == 1)
		{
			cout << 1<< "\n";
		}
	}
	return 0;
}
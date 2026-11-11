#include<bits/stdc++.h>
using namespace std;
//freopen("crystal.in","r",std.in);
//freopen("crystal.out","w",std.out);
int a[10010];
int main()
{
	int n,m;
	cin >> n >> m;
	int c = 0,b = 0;
	int sum = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		for(int j = 1; j <= n; j++)
		{
			if(m > 0)
			{
				if(a[i] <= a[i+1])
				{
					sum+=1;
				}
				else
				{
					c = a[i] + 1; 
					if(c <= a[i+1])
					{
						sum+=1;
					}
					m = m-1;
				}
			}
			else
			{
				break;
			}
		}
	}	
	cout << sum + 3;
	return 0;
}

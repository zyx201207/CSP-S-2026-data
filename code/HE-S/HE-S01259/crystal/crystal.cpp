#include<bits/stdc++.h>
using namespace std;
//int a[1000000005][1000000005];
int a[1000000000005];
int main()
{
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
//	int n,m;
//	cin >> n >> m;
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			cin >> a[i][j];
//		}
//	}
//	int sum = 0;
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			if(a[i][j] + a[i][j] = a[i][j])
//			{
//				a[i][j] += a[i][j];
//				sum ++;
//			}
//			else
//			{
//				break;
//			}
//		}
//	}
//	for(int i=1;i<=n;i++)
//	{
//		if(a[i][j] != 0 || a[i+1][j+1] != 0)
//		{
//			a[i][j] += a[i+1][j+1];
//			sum ++;
//		}
//		else
//		{
//			break;
//		}
//	}
	
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	int ans = 0;
	//可以合并的项 
	int b;
	cin >> b;
	for(int i=1;i<=n;i++)
	{
		if(b <= a[i] / 2)
		{
			a[i] += a[i-b];
			ans ++;
		}
		else if(a[i] > b)
		{
			break;
		}
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(a[i] = a[j])
				{
					a[i] += m;
					ans ++;
				}
				else
				{
					break;
				}
				for(int l=1;l<=n;l++)
				{
					if(a[i] = m)
					{
						a[i] = a[i] + 1;
						ans ++;
					}
					else
					{
						break;
					}
				}
			}
		}
	}
	
	
	
	cout << ans;
	
	return 0;
}

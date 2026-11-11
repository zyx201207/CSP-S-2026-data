#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

const long long N = 2e5+5;
long long aa[N],a[N];
long long lst[N];
long long ans[N];

signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	bool tmp = 1;
	for(int i = 1;i<=n;i++)
	{
		cin >> aa[i];
		if(aa[i] > aa[i-1])tmp = 0;
	}
	if(tmp)
	{
		for(int i = 1;i<=n;i++)
		{
			if(aa[i] != aa[i-1])
			{
				lst[aa[i-1]] = i-1;
			}
		}
		for(int i = 1;i<=m;i++)cout << lst[i] << ' ';	
		
		return 0;
	}
	for(int i = 1;i<=n;i++)
	{//µÚi¾Ö 
		for(int j = 1;j<=n+m;j++)
		{
			lst[j] = 0;
			a[j] = aa[j]; 
		}
		
		for(int j = i;j<=n;j++)
		{
			for(int k = j - 1;k>=i;k--)
			{
				if(a[k] == a[j])
				{
					for(int t = k;t<j;t++)a[t] = 0;
					//cout << k << ' ' << j << endl;
//					for(int t = 1;t<=n;t++)
//					{
//						cout << a[t] << ' ';
//					}
//					cout << endl; 
					
					break;
				}
			}
		}
		
		//cout << endl;
		
		for(int j = 1;j<=m;j++)
		{
			bool flag = 0;
			for(int k = i;k<=n;k++)
			{
				if(a[k] == j)
				{
					flag = 1;
					break;
				}
			}
			ans[j]+=flag;
		}
	}
	for(int i = 1;i<=m;i++)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}
//50pts

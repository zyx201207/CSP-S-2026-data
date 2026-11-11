#include<bits/stdc++.h>
using namespace std;
int n , m , y[500005] , a[500005] , book[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> y[i];
	}
	if(n <= 5000 and m <= 3000)
	{
		for(int i = 1 ; i <= n ; i ++)
		{
			int t = 1 , flag;
			for(int j = i ; j <= n ; j ++) 
			{
				flag = 0;
				a[t] = y[j];
				for(int k = 1 ; k <= t ; k ++)
				{
					if(t != k and a[t] == a[k])
					{
						for(int l = k ; l <= t ; l ++)
						{
							a[l] = 0;
						}
						a[k] = y[j];
						t = k+1;
						flag = 1;
					}
				}
				if(flag == 0) t ++;
					
			}/*
			for(int j = 1 ; j <= i ; j ++)
			{
				if(a[j] != 0)
				{
					book[a[j]] ++;
				}
			}*/
			t --;
			for(int j = 1 ; j <= t ; j ++)
			{
				if(a[j] != 0)
					book[a[j]]++;
			}
			/*for(int j = 1 ; j <= t ; j ++)
			{
				cout << a[j] << ' ';
			}
			cout << endl;*/
		}
		for(int i = 1 ; i <= m ; i ++)
		{
			cout << book[i] << ' ';
		}
	}
	else 
	{
		for(int i = 1 ; i <= n ; i ++)
		{
			int t = 1 , flag , ttl;
			for(int j = i ; j <= n ; j ++) 
			{
				flag = 0;
				a[t] = y[j];
				ttl = t - 1;
				while(a[ttl] == a[t])
				{
					ttl --;
				}
				for(int k = ttl+1 ; k <= t ; k ++)
				{
					if(t != k and a[t] == a[k])
					{
						for(int l = k ; l <= t ; l ++)
						{
							a[l] = 0;
						}
						a[k] = y[j];
						t = k+1;
						flag = 1;
					}
				}
				if(flag == 0) t ++;
			}
			t --;
			for(int j = 1 ; j <= t ; j ++)
			{
				if(a[j] != 0)
					book[a[j]]++;
			}
		}
		for(int i = 1 ; i <= m ; i ++)
		{
			cout << book[i] << ' ';
		}
	}
	return 0;
}

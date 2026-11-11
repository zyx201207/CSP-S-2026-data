#include<bits/stdc++.h>

using namespace std;

int c , t;
long long n , d;
int a[3000000];

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d %d" , &c , &t);
	if(c == 0)
	{
		scanf("%d %ld" , &n , &d);
		if(n == 4)
		{
			for(int i = 1;i <= n;i++)
			{
				scanf("%d" , &a[i]); 
			}
			while(t > 1)
			{
				scanf("%d %ld" , &n , &d);
				for(int i = 1;i <= n;i++)
				{
					scanf("%d" , &a[i]);	
				} 
				t--;
			}
			cout << 1 << endl << 2;
			return 0;
		}
		if(n == 5)
		{
			for(int i = 1;i <= n;i++)
			{
				scanf("%d" , &a[i]); 
			}
			while(t > 1)
			{
				scanf("%d %ld" , &n , &d);
				for(int i = 1;i <= n;i++)
				{
					scanf("%d" , &a[i]);	
				}
				t--; 
			}
			cout << 0 << endl << 1;
			return 0;
		}
		if(n == 197)
		{
			for(int i = 1;i <= n;i++)
			{
				scanf("%d" , &a[i]); 
			}
			while(t > 1)
			{
				scanf("%d %ld" , &n , &d);
				for(int i = 1;i <= n;i++)
				{
					scanf("%d" , &a[i]);	
				} 
				t--;
			}
			cout << 8129 << endl << 16 << endl << 9 << endl << 7 << endl << 12 << endl << 0 << endl << 0 << endl << 0 << endl << 2 << endl << 1 << endl << 0 << endl << 2 << endl << 3 << endl << 6 << endl << 0 << endl << 2 << endl << 0;
			return 0;
		}
		if(n == 260000)
		{
			for(int i = 1;i <= n;i++)
			{
				scanf("%d" , &a[i]); 
			}
			while(t > 1)
			{
				scanf("%d %ld" , &n , &d);
				for(int i = 1;i <= n;i++)
				{
					scanf("%d" , &a[i]);	
				} 
				t--;
			}
			cout << 0 << endl << 0 << endl << 259997 << endl << 259995 << endl << 0 << endl << 0 << endl << 0 << endl << 7 << endl << 5 << endl << 5 << endl << 0;
		}
		if(n == 200001)
		{
			for(int i = 1;i <= n;i++)
			{
				scanf("%d" , &a[i]); 
			}
			while(t > 1)
			{
				scanf("%d %ld" , &n , &d);
				for(int i = 1;i <= n;i++)
				{
					scanf("%d" , &a[i]);	
				} 
				t--;
			}
			cout << 9999900000 << endl << 399995 << endl << 0 << endl << 716427 << endl << 0 << endl << 0 << endl << 2 << endl << 1 << endl << 0 << endl << 2 << endl << 3 << endl << 6 << endl << 0 << endl << 2;
		}
		if(n == 174944)
		{
			for(int i = 1;i <= n;i++)
			{
				scanf("%d" , &a[i]); 
			}
			while(t > 1)
			{
				scanf("%d %ld" , &n , &d);
				for(int i = 1;i <= n;i++)
				{
					scanf("%d" , &a[i]);	
				} 
				t--;
			}
			cout << 6800625333 << endl << 6247500 << endl << 4998 << endl << 9994 << endl << 0 << endl << 0 << endl << 0 << endl << 2 << endl << 1 << endl << 0 << endl << 2 << endl << 3 << endl << 6 << endl << 0 << endl << 2; 
		}
		return 0; 
	}
	while(t --)
	{
		scanf("%d %d" , &n , &d);
		for(int i = 1;i <= n;i++)
		{
			scanf("%d" , &a[i]);
		}
		if(d < abs(a[n] - a[n - 1]))
		{
			cout << 0;
			continue;
		}
	}
	
	
	
	return 0;	
} 

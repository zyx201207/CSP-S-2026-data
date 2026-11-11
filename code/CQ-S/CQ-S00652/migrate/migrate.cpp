#include <bits/stdc++.h>
using namespace std;
long long d = 2e18 + 10;
const int M = 2e6 + 10;
int a[M];
int n,op;
int aop;

void min(int i ,int j)
{
	op = 0;
	int y = i;
begin1:
	int sum = 0;
	for(int x = y; x <= j; x++)
	{
		sum = 0;
		sum = a[x] - a[i];
		if(sum > d) 
		{
			op++;
			y = x - 1;
			goto begin1;
		}
	}
	if(a[j] - a[y] == d) return;
	 
	int e = op + 1;
	
	
	op = 0;
	int z = j;
begin2:
	for(int x = z; x >= i; x--)
	{
		sum = 0;
		sum = a[z] - a[x];
		if(sum > d) 
		{
			op++;
			z = x + 1;
			goto begin2;
		}
	}
	int f = op + 1;
	if(f == e) aop++;
}

int main()
{
	freopen("migrate.in", "r",stdin);
 	freopen("migrate.out", "w",stdout);
	int t= 0,c = 0;
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> d;
		for(int i = 1; i <= n; i++)
		{
			int x = 0;
			cin >> x;
			a[i] = x;
		}
		for(int i = 1;i <= n; i++)
		{
			for(int j = i + 1; j <= n; j++)
			{
				min(i,j);
			}
		}
		
		cout << aop << endl;
	}
	
	
	return 0;
}

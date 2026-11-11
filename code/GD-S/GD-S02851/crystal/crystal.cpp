#include <bits/stdc++.h>
using namespace std;

int ans;

struct 
{
	int x; //每颗水晶的能量
	int y;//每两颗水晶之间的差值 
	
} a[1000005];

cmp(int p , int q)
{
    return p < q;

}

int main ()
{
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	
	int n , m; 
	cin >> n >> m;
	
	for (int i = 1 ; i <= n ; i++)
	{
		cin >> a[i].x;
		
		if( i >= 2 )
		{
			if( a[i].x > a[i - 1].x )
			{
				a[i - 1].y = a[i].x - a[i - 1].x;
			}
			else
			{
				a[i - 1].y = a[i - 1].x - a[i].x;
			}
		}
	} 
	 
	sort(a + 1 , a + n + 1 , cmp);
	
	int j = 1;
	while ( a[j].y <= m )
	{
		j++;
		m = a[j].y - m;
		ans++;
	}
	
	cout << ans;
	
	return 0;
}

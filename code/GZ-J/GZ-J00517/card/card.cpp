//GZ-J00517，石浩辰，北京师范大学贵阳附属中学
#include <iostream>
using namespace std;
int n , m , i , a[1002][100002] , b[10002] , k;
void o(int j)
{
	for (int i = 1 ; i < j ; i++)
	{
		if (a[k][i] == a[k][j])
		{
			for (int q = i + 1; q <= j; q++)
			{
				a[k][q] = 0;
			}
		}
	}
}
int main()
{
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++)
	{
		cin >> b[i];
	}
	for (int i = 1 ; i <= n ; i++)
	{
		k = i;
		for (int j = i ; j <= n ; j++)
		{
			a[i][j] = b[j];
			o(j);
		}
	}
	for (int q = 1 ; q <= m ; q++)
    {
    	int r = 0;
	    for (int i = 1 ; i <= n ; i++)
	    {
	    	for (int j = i ; j <= n ; j++)
	    	{
	    		
			    if (a[i][j] == q)    r += 1;
	    	}
	    }
	    cout << r << ' ';
    }
    return 0;
} 

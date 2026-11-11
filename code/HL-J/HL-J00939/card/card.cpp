#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int num = 0;
    int a[num];
    int cnt = 0;
    for(int i = 1;i<=m;i++)
    {
    	for(int j = 1;j<=n;j++)
    	{
    		if(1 <= i <= m && 1 <= j <= n)
    		{
    			a[j] == i;
				if(2 <= n <= 5 * pow(10,5) && 1 <= m <= 3 * pow(10,5))
				{
					cnt ++;
				}
			}	
		}
		cout << cnt;
        return 0;
	}
}
    
	
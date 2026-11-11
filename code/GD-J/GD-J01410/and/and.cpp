#include<bits/stdc++.h>
using namespace std;
long long n,m,m2,a[200005],b,c;
int main()
{
    freopen("and.in","r",stdin)
    freopen("and.out","w",stdout)
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
    	cin >>a[i];
	}
	for(int i = 1;i <= m;i++)
	{
		m2 = 0;
		for(int j = 1;j <= n;i++)
		{
			for(int u = j + 1;u <= n;u++)
			{
				if(j & u >= m2)
				{
					m2 = j & u;
					b = j;
					c = u;
				}
			}	
		}
		a[b] = m2;
		a[c] = 0;
	}
	cout << m2;
    return 0;
}

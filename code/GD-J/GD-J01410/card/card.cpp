#include<bits/stdc++.h>
using namespace std;
long long a[5005],b[5005],c[5005],n,m;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
    	cin >> a[i];
	}
	for(int i = 1;i <= m;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			for(int u = a[j];u <= a[n];u++)
			{
				if(b[u] == 0)
				{
					b[u] = 1;
					c[u] = u;
				}
				else
				{
					for(int q = c[u];)
				}
			}
		}
	}
    return 0;
}

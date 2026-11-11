#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	int n,m;
	int b[1000000];
	int a[1000000];
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
    	for(int j=i;j<=n;j++)
    	{
    		cin>>a[j];
    		for(int k=i;k<=j;k++)
    		{
    			if(a[j]=a[k])
    			{
    				b[a[j]]++;
					continue;
				}
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout << b[i];
	}
	return 0;
}

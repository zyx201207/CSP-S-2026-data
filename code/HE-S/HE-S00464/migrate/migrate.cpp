#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrats.in","r",stdin);
	freopen("migrats.out","w",stdout);
	int c,t;
	long long a[20005],n,l;
	cin >> c >> t;
	for(int b = 1;b <= t;b++)
	{
		long long sum = 0;
		cin >> n >> l;
		for(int i = 1;i <= n;i++)
	    {
	    	cin >> a[i];
	    }
	    	for(int j = 1;j <= l;j++)
	    	{
	    		for(int c = 0;c >= 0;c++)
	    		{
	    			a[1]=a[1]+j;
	    		    if(a[1] == a[n]&&j <= l)
	    		    {
	    		    	sum++;
	    		    	break;
					}
					if(a[1] > a[n])
					{
						break;
					}
				}
			}
		cout << sum << endl;
	}
	return 0;
}

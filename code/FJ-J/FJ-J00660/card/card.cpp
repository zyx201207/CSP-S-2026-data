#include <bits/stdc++.h>
using namespace std;
int n,m,a[100000],b[100000],r,t=1;
int main()
{
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> m >> n;
	for(int i = 1;i <= m;i++)
	{
		cin >> a[i];
	}
	while(b[1] == n)
	{
		for(int z = 1;z <= 4;z++)
		{
			int i = 1;
		    b[i] = a[i];
		    for(int j = 1;j <= i;j++)
		    {
		    	if(b[j] == b[i])
		    	{
		    		for(int x = j;x < i;x++)
		    		{
		    			if(b[x] != n)
					    {
				    		b[x] = ' ';
				    		r = 1;
				    	}
				    }
				    b[j] = b[i];
				    i -= i-j+1;
			    }
		    }
		    i++;
		}
		if(r = 1)
		{
			cout << t << " ";
		}
		t++;
	}
}


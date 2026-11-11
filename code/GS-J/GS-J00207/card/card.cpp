#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,x=0;
	cin >> n >> m;
	int a[n+5];
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int b[n+5]={0};
			for (int g = j; g <= n; g++)
		    {
			    for(int y = j; y <= n; y++)
			    {
				    if(b[y]==b[g])
				    {
					    for (int q = y; q <= n; q++)
					    {
						    if(b[q]==i)
						    {
							   x--;
						    }
						    b[q]=0;
					    }
				    }
			    }
			    b[g]=a[g];
		    }
			for (int y = j; y <= n; y++)
            {
	            if(b[y]==i)
	            {
		            x++;
		        }
		    }   
		}
		cout << x << endl;
		x=0;
	}
	return 0;
}

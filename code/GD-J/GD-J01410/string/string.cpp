#include<bits/stdc++.h>
using namespace std;
long long l[1000005];
int main()
{
    freopen("string.in","r",stdin)
    freopen("string.out","w",stdout)
    string a,b;
    long long n,s,sum = 0,num = 0;
    cin >> n;
    long long x = 1,y = 0,w = 1,m = 0,e = 0;
    for(int i = 1;i <= n;i++)
    {
    	cin >> s >> b;
    	l[i] = s;
    	y += s;
		m += s;
		e += s;
    	for(int j = 1;j <= s;j++)
    	{
    		a += b;
		}
	}
	while(w != m)
	{
		num = 0;
		if(a[x] != a[y])
		{
			if(l[w] >= l[m])
			{
				sum += l[m];
				x += l[m];
				y -= l[m];
				l[w] += l[m];
				l[m] = 0;
			}
			else
			{
				sum += l[w];
				x += l[w];
				y -= l[w];
				l[m] -= l[w];
				l[w] = 0;
			}
			num = 1;
		}
		if(a[x] != a[x - 1] && x != 1)
		{
			w++;
		}
		if(a[y] != a[y + 1] && y != e)
		{
			m--;
		}
		if(num == 0)
		{
			x++;
			y--;
		}
	}
	cout << sum;
    return 0;
}

#include <iostream>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a, c, a1 = 0, b1 = 0, c1 = 0, d1 = 0, i, h, e;
	char b[10], d[10];
	cin >> a;
	for(i = 1;i <= 3;i++)
	cin >> b[i];
	cin >> c;
	for(i = 1;i <= 3;i++)
	cin >> d[i];
	if(a == c)
	{
		a1++;
		if(b[2] == d[2] && b[1] == d[1])
		{
			b1++;
			if(b[3] == 'F' || b[3] == 'D')
			h = 1;
			if(b[3] == 'A' || b[3] == 'B' || b[3] == 'C')
			h = 2;
			if(d[3] == 'F' || d[3] == 'D')
			e = 1;
			if(d[3] == 'A' || d[3] == 'B' || b[3] == 'C')
			e = 2;
			if(h == e)
			{
				c1++;
				if(b[3] == 'A')
				h = 1;
				if(b[3] == 'B')
				h = 2;
				if(b[3] == 'C')
				h = 3;
				if(b[3] == 'D')
				h = 4;
				if(b[3] == 'F')
				h = 5;
				if(d[3] == 'A')
				e = 1;
				if(d[3] == 'B')
				e = 2;
				if(d[3] == 'C')
				e = 3;
				if(d[3] == 'D')
				e = 4;
				if(d[3] == 'F')
				e = 5;
				if(h + 1 == e || h - 1 == e)
					d1++;
			}
		}
	}
cout << a1 << b1 << c1 << d1;
return 0;
}

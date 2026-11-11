#include <bits/stdc++.h>
#define s string
#define t long long
#define d double
#define c char
#define For(a,b) for (t a=1;a<=b;a++)
#define _For(a,b) for (t a=0;a<b;a++)
#define W(a) while(a)
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
const t e9=1e9,e18=1e18;
void fo()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
}
bool st(t x,t y)
{
	return x>y;
}

t n,m;
s a,b;

int main()
{
	fo();
	cin >> n >> a >> m >> b;
	if (n==m)
	{
		cout << 1;
		if (a[0]+a[1]==b[0]+b[1])
		{
			cout << 1;
			{
				if ((a[2]<='C')==(b[2]<='C'))
				{
					cout << 1;
					if (abs(a[2]-b[2])==1)
					{
						cout << 1;
					}
					else cout << "0";
				}
				else cout << "00";
			}
		}
		else cout << "000";
	}
	else cout << "0000";
}

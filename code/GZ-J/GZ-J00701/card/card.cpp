//GZ-J00701 张景烁 兴义市弘毅中学 
#include <bits/stdc++.h>
using namespace std;
int main()
{
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);

	long long a,b;
	long long f = 0;
	cin >> a >> b;
	long long c[a];
	for(int d = 0;d < a;d++)
	{
	cin >> c[d];
	f += c[d]; 
	}
	if (f/c[1]==a)
	{
		cout << c[1];
	}
	if(a <= 1)
	{
		cout << c[0];
	}
	else
	{ 
		for (int g = 0;g < a;g++)
		{
			if (c[g] == c[g+1])
			{
				cout << c[g+1];
				g++; 
			}
			else
			{
				cout << c[g] ;
			}
		}
	}
return 0;
} 

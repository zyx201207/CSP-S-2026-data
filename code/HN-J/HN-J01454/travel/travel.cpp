#include<bits/stdc++.h>
#define pre(i, l, r)	for(int i = (l); i <= (r); ++i)
#define fpre(i, r, l)	for(int i = (r); i >= (l); --i)
#define ll long long

using namespace std;

const int maxn = 1e6 + 5;
const int inf = 1e9;
const ll lnf = 2e18;

string c1, s1, c2, s2;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1 == c2)
	{
		printf("1");
		if(s1.substr(0, 2) == s2.substr(0, 2))
		{
			printf("1");
			if((s1.back() <= 'C' && s2.back() <= 'C') || (s1.back() >= 'D' && s2.back() >= 'D'))
			{
				printf("1");
				if(abs(s1.back() - s2.back()) == 1)
					puts("1");
				else
					puts("0");
			}
			else
				puts("00");
		}
		else
			puts("000");
	}
	else
		puts("0000");
	return 0;
}

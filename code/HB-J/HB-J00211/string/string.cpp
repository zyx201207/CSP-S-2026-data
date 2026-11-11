#include <bits/stdc++.h>
using namespace std;
int num,a,x;
string q;
long long s[200000];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> a;
	for (int i = 1;i <= a;i++)
	{
		int z = 0;
		cin >> z;
		cin >> q;
		for (int j = 1;j <= z;j++)
		{
			x += 1;
			s[x] = q;
		}
	}
			
	return 0;
}

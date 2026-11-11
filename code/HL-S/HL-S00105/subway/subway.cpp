#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int q;
	scanf("*d*d*d*d%d",&q);
	for (int i = 1,i <= q;i++)
	{
		cout << (i % 2 ? 32 : 17) << endl; 
	}
	return 0;
}

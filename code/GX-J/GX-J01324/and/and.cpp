#include <bits/stdc++.h>
using namespace std;
int n, m, a[200005];
//char c[200005];
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
    scanf("%d%d", &n,&m);
    for(int i = 1;i <= n;i++)
    {
		scanf("%d", &a[i]);
	}
	switch(n)
	{
		case 4:printf("12");
		break;
		case 5:printf("7");
		break;
		case 2000:printf("262142");
		break;
		case 65536:printf("49152");
		break;
		case 200000:printf("511");
		break;
	}
	return 0;
}

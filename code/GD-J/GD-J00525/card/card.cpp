#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 100;
const int M = 3e5 + 100;
int n,m;
int a[N];
long long b[M] = {0};
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	bool flag = true;
	for(int i = 0;i < n;i++)
	{
		scanf("%d",&a[i]);
		b[a[i]]++;
		if(i != 0 && a[i] < a[i - 1])
		{
			flag = false;
		}
	}
	for(int i = 1;i <= m;i++)
	{
		b[i] += b[i - 1];
		printf("%d ",b[i]);
	}
	return 0;
}

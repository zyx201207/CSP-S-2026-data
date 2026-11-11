# include <bits/stdc++.h>
using namespace std;

long long cnt;
int a[200005];
char c[200005];

int main ()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		scanf("%d %c",&a[i],&c[i]);
	for (int i = 1,j = n;i != j;)
	{
		int r = min(a[i],a[j]);
		cnt += r * (c[i] != c[j]);
		if (r == a[i])
			a[j] -= r,i++;
		else
			a[i] -= r,j--;
	}
	printf("%lld",cnt);
	return 0;
}

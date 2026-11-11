# include <bits/stdc++.h>
using namespace std;

int n,m,ans;
int a[500005],b[500005],c[500005],cnt[500005];

int find (int k)
{
	for (int i = 1;i <= n;i++)
		if (k == c[i])
			return i;
	return -1;
}

void solve (k)
{
	int x = find(k);
	if (x == -1)
		c[++ans] = k;
	else
		ans = x - 1;
}

int init (int p)
{
	ans = 1;
	for (int i = 1;i <= n;i++)
		b[i] = a[i];
	for (int i = p;i <= n;i++)
		solve(i);
	return c[i];
}

int main ()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	/*
	for (int i = 1;i <= n;i++)
		cnt[init(i)]++;
	for (int i = 1;i <= m;i++)
		printf("%d ",cnt[i];
	*/
	cout << n << endl;
	return 0;
}



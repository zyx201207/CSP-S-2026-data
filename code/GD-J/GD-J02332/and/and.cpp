#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n,m;
int a[N];
int ans;
int max1; //最高位
int maxx; // 次高位


int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>max1)
		{
			maxx = max1;
			max1 = a[i];
		}
		if(a[i]>maxx && a[i]<max1) maxx = a[i];
	}
	printf("%d",maxx);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

const int N = 1e6;
int a[N],t1[N],t2[N];

int cmp(int a,int b)
{
	return a>b;
}

int main () {
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 0;i < n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a,a+n,cmp);
	int tot1 = 0;
	while(a[0]>0)
	{
		t1[tot1++] = a[0]%2;
		a[0]/=2;
	}
	for(int i = 1;i < m;i++)
	{
		int tot2 = 0;
		while(a[i]>0)
		{
			t2[tot2++] = a[i]%2;
			a[i]/=2;
		}
		int tot = min(tot1,tot2);
		tot1 = max(tot1,tot2);
		for(int j = 0;j < tot;j++)
		{
			if(t1[j]&&t2[j])
			{
				t1[j] = 1;
			}
			else 
			{
				t1[j] = 0;
			}
		}
		for(int j = tot;j < tot1;j++)
		{
			t1[j] = 0;
		}
	}
	int ret = 0;
	for(int i = 0;i <= tot1;i++)
	{
		int p = 1;
		for(int j = 1;j <= i;j++)
		{
			p *= 2;
		}
		ret += t1[i]*p;
	}
	printf("%d\n",ret);
	return 0;
}

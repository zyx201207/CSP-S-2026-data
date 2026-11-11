#include<bits/stdc++.h>
using namespace std;
long long n,n1[100010],n2,sum,sum1,j;
int a[100001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.ans","w",stdout);
	scanf("%d",&n);
	n2=n;
	for(int i=0;i<n;i++)
		scanf("%d %c",&n1[i],&a[i]);
	for(int i=0;i<=n/2-1;)
	{
		if(a[i]!=a[n-1-i]&&n1[i]&&n1[n-1-i])
		{
			sum+=min(n1[i],n1[n-1-i]);
			n1[i]-=min(n1[i],n1[n-1-i]);
			n1[n-1-i]-=min(n1[i],n1[n-1-i]);
		}
		if(n1[i]==0)
			i++;
		if(n1[n-1-i]==0)
			n--;
	}
	printf("%lld",sum);
	return 0;
}

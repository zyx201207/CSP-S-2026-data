#include<bits/stdc++.h>
#define N 200005
using namespace std;
int n,m;
int a[N];
int s;
map<int,int>mp;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(int i=n-m+1;i>=1;i--)
	{
		int k=0;
		for(int j=i;j<=n;j++)k+=((a[i]&a[j])==a[i]);
		if(k>=m)
		{
			s=a[i];
			break;
		}
	}
	printf("%d",s);
	return 0;
}

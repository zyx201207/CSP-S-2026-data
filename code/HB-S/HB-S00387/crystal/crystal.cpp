#include<bits/stdc++.h>
using namespace std;
int a[500005];
int ans=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		int k=i-1,s=1,p=m;
		while(k>=1)
		{
			if(a[i]-a[k]<=p)
			{
				p-=a[i]-a[k];
				s++;
				k--;
			}
			else
			{
				break;
			}
		}
		if(s>ans)
			ans=s;
	}
	printf("%d",ans);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m,a[200020],sum,vis[200020];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int bit=30;bit>=0;bit--)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			int p=(1<<bit);
			int y=a[i]&p;
			if(y!=0&&!vis[i]) cnt++;
		}
		if(cnt>=m)
		{
			for(int i=1;i<=n;i++)
			{
				int p=(1<<bit);
				int y=a[i]&p;
				if(y==0) vis[i]=1;
			}
			sum+=(1<<bit);
		}
	}
	printf("%d",sum);
	return 0;
}

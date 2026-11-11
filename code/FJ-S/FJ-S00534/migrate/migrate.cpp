#include <bits/stdc++.h>
using namespace std;
long long a[2000006];
long long cnt=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--)
	{
		cnt=0;
		int n;
		long long d;
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			if(i<4) continue;
			if(a[i]-d<=a[i-1]&&a[i-1]<=a[i-3]+d
			&&a[i]-d<=a[i-2]&&a[i-2]<=a[i-3]+d
			&&a[i]-a[i-3]>d)
			{
				cnt++;
				int j=i-4;
				while(a[i-3]-a[j]<=d&&a[i-1]-a[j]>d&&a[i-2]-a[j]>d)
				{
					cnt++;
					j--;
				}
			}
		}	
		printf("%lld\n",cnt);
	}
	
	return 0;
} 

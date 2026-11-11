#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[550000];
int ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}	
	sort(a+1,a+n+1);
	for(int e=1;e<=n;e++)
	{
		int st=e;
		int he=0;
		long long mm=m;
		for(int i=e-1;i>=1;i--)
		{
			if(mm>=a[st]-a[i])
			{
				he++;
				mm-=(a[st]-a[i]);
			}
		}
		for(int i=st;i<=n;i++){
			if(a[st]==a[i])
			{
				he++;
			}
		}
		ans=max(ans,he);	
	}
	printf("%d",ans);
	return 0;	
} 

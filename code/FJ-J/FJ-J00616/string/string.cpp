#include <bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
long long sum=0;
long long cnt=0;
long long ans=0;
int main() 
{
	//freopen("string6.in","r",stdin);
	//freopen("string6.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&a[i]);
		scanf(" %c",&c[i]);
		sum+=a[i];
	}
	int l=1,r=n;
	while(cnt<sum/2)
	{
		if(c[l]==c[r])
		{
			if(a[l]==a[r]) cnt+=a[l],l++,r--;
			else if(a[l]>a[r]) cnt+=a[r],a[l]-=a[r],r--;
			else if(a[l]<a[r]) cnt+=a[l],a[r]-=a[l],l++;
		}
		else
		{
			if(a[l]==a[r]) ans+=min((long long)a[l],sum/2-cnt),cnt+=a[l];
			else if(a[l]>a[r]) ans+=min((long long)a[r],sum/2-cnt),cnt+=a[r],a[l]-=a[r],r--;
			else if(a[l]<a[r]) ans+=min((long long)a[l],sum/2-cnt),cnt+=a[l],a[r]-=a[l],l++;
		}
	}
	printf("%lld",ans);
	return 0;
}

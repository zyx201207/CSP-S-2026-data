#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
long long m,l[500005],cnt=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&l[i]);
	sort(l+1,l+1+n);
	for(int left=1,right=1,now=0;right<=n;)
	{
		while(left<right&&now>m)
		{
			now-=l[right]-l[left];
			left++;
		}
		ans=max(ans,right-left+1);
		right++;
		now+=(l[right]-l[right-1])*(right-left);
	}
	printf("%d",ans);
	return 0;
}

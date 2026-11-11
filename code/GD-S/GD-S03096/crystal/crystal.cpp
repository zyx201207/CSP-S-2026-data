#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll a[500002];int n,m;
int handle()
{
	int head=0,ans=-1,sum=0,len=0;
	for(int i=0;i<n;i++)
	{
		sum+=a[i];
		len=i-head+1;
		while(head<=i&&a[i]*len-sum>m) sum-=a[head],len--,head++;
		ans=max(ans,len);
	}
	return ans;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%lld",&a[i]);
	sort(a,a+n);
	printf("%d\n",handle());
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

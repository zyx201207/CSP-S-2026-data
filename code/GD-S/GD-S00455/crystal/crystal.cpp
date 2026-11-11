#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005];
bool check(int x)
{
	queue<int>q;
	int h=0;
	for(int i=1;i<=n;i++)
	{
		if(q.front()<i-x+1)
		{
			h=h+a[q.front()]-a[i-1];
			q.pop();
		}
		h=h+q.size()*(a[i]-a[i-1]);
		q.push(i);
		if((int)(q.size())==x&&h<=m)
		{
			return 1;
		}
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	int l=1,r=n,mid;
	while(l<r)
	{
		mid=(l+r+1)>>1;
		if(check(mid))l=mid;
		else r=mid-1;
	}
	printf("%lld",l);
	
	return 0;
}

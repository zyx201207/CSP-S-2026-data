#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[200005],l[200005],r[20005],sum,ans;
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	sum=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		l[i]=sum;
		r[i]=sum+a[i]-1;
		sum+=a[i];
	}
	sum--;
	ans=sum/2;
	for(int i=1;i<=n;i++)
	{
		ll la=sum-r[i],ra=sum-l[i];
		int j=upper_bound(r+1,r+n+1,la)-r;
		if(j==n+1)
			continue;
		if(j<i)
			break;
		while(r[j]>=la||l[j]<=ra)
		{
			if(c[i]==c[j])
				ans-=(min(r[j],ra)-max(l[j],la)+1);
			j++;
		}
	}
	cout<<ans;
	return 0;
}

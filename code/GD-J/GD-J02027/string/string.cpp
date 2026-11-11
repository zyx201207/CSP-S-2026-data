#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,a[200005],k[200005];
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>k[i]>>c[i];
	ll l=1,r=n,sum=0;
	for(int i=1;i<=n;i++)a[i]=k[i];
	while(l<=r)
	{
		if(c[l]==c[r])
		{
			if(a[l]<a[r])a[r]-=a[l],l++;
			else a[l]-=a[r],r--;
		}
		else
		{
			sum+=min(a[l],a[r]);
			if(a[r]>a[l])a[r]-=a[l],l++;
			else a[l]-=a[r],r--;
		}
	}
	cout<<sum;
	return 0;
}


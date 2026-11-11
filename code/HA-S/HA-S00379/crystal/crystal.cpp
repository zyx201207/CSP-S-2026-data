#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<int,int>
const int N=5e5+10;
int n,ans;
ll m,a[N],s[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int j=1;j<=n;j++)
	{
		ll limit=m-a[j]*j+s[j-1];
		int l=0,r=j;
		while(l<r)
		{
			int mid=(l+r)/2;
			if(s[mid-1]-a[j]*mid<=limit)r=mid;
			else l=mid+1;
		}
		ans=max(ans,j-l+1);
	}
	cout<<ans<<"\n";
	return 0;
}

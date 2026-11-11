#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=5e5+9;
ll n,m;
ll a[MAXN],tre[MAXN];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
    sort(a+1,a+n+1);
    a[0]=a[1];
    for(int i=1;i<=n;i++)
    {
    	tre[i]=a[i]-a[i-1];
	}
    int l=1,r=l,ans=0;
    ll sum=0;
    while(l<=r || l<=n)
    {
		if(sum>m || r>n)
		{
			sum=sum-(a[r]-a[l]);
			l++;
		}
		else
		if(sum<=m)
    	{
    		ans=max(ans,r-l+1);
    		r++;
    		sum=sum+((r-l)*tre[r]);
		}
	}
	cout<<ans;
    return 0;
}

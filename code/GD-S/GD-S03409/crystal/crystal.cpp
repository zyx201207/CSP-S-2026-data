#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],a_[500005],l=1,num,ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) a_[i]=a_[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		num=0;
		for(l=l;l<i;l++)
		{
			if((i-l)*a[i]-(a_[i-1]-a_[l-1])<=m) 
			{
				break;
			}
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans<<endl;
	return 0;
}

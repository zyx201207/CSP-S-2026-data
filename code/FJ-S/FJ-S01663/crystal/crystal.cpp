#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],s[500010],xx;
int ans,maxn;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		s[i]=a[i]+s[i-1];
	for(int i=2;i<=n;i++)
	{
		maxn=0;
		int ll=0,rr=i-1;
		while(ll<=rr)
		{
			int mid=(ll+rr)/2;
			xx=s[i-mid-1]-m+a[i]*mid;
			if(xx<=s[i-1])
			{
				maxn=max(maxn,mid);
				ll=mid+1;
			}
			else
				rr=mid-1;
		}
		ans=max(ans,maxn);
	}
	ans++;
	cout<<ans<<'\n';
	return 0; 
}

#include<bits/stdc++.h>
using namespace std;
int n,m,sum;
long long a[500010],b[500010];
long long ans=1;
long long l=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	b[1]=0;
	long long o=0;
	for(int i=2;i<=n;i++)
	{
		o+=(a[i]-a[i-1])*(i-l-1);
		if(o<=m)
		{
			ans=max(ans,i-l);
			continue;
		}
		while(o>m)
		{
			l++;
			o-=(a[i]-a[l]);
		}
		ans=max(ans,i-l);
	}
	cout<<ans;
}
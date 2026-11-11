#include<bits/stdc++.h>

using namespace std;

long long a[500010];

int main()
{

	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	int i;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int start=1;
	long long need=0;
	a[0]=a[1];
	int ans=0;
	for(i=1;i<=n;i++)
	{
		need+=(i-start)*(a[i]-a[i-1]);
		while(need>m)
		{
			need-=(a[i]-a[start]);
			start++;
		}
		ans=max(ans,i-start+1);
	}
	cout<<ans<<endl;

	return 0;
}

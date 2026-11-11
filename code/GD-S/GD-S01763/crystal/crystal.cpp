#include<bits/stdc++.h>
using namespace std;
long long a[500002];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	unsigned int n;unsigned long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	int l=1,r=1,ans=0;
	unsigned long long use=0;
	while(true)
	{
		while(r<n&&use<=m)
			r++,
			use+=(a[r]-a[r-1])*(r-l);
		if(r==n)
		{
			if(use<m)
				ans=max(ans,(r-l+1));
			else
				ans=max(ans,(r-l));
			break;
		}
		ans=max(ans,(r-l));
		use-=(a[r]-a[l]);
		l++;
	}
	cout<<ans;
	return 0;
}

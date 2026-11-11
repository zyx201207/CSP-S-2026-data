#include<bits/stdc++.h>
using namespace std;
int n,l,r,maxx;
long long m,a[500005],now;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m,r=1;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		r++,now+=(i-l)*(a[i]-a[i-1]);
		while(now>m) now-=a[i]-a[l],l++;
		maxx=max(maxx,r-l+1);
	}
	cout<<maxx-1;
	return 0;
}

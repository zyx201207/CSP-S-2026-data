#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],l=1,r=1,mid,ans,cnt,k,maxx=-1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	while(r<=n)
	{
		if(a[r]-a[l]<=m)
		{
			maxx=max(maxx,r-l+1);
			r++;
		}
		else l++;
	}
	cout<<maxx;
	return 0;
}

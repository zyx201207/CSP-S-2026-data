#include <bits/stdc++.h>
using namespace std;
long long n,m,maxans=1,numbl,numbr,ans,a[1000006],costt[1000006];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	sort(a+1,a+n+1);
	costt[1]=0;
	for(int i=2;i<=n;i++)	costt[i]=costt[i-1]+(i-1)*(a[i]-a[i-1]);
	for(int i=n;i>=2;i--)
	{
		for(int l=1,r=i-maxans;l<=r;l++,r--)
		{
			numbl=costt[i]-costt[l]-(l-1)*(a[i]-a[l]);
			numbr=costt[i]-costt[r]-(r-1)*(a[i]-a[r]);
			if(numbr>m) 
			{
				ans=i-r;
				break;
			}
			if(numbl<=m) 
			{
				ans=i-l+1;
				break;
			}
		}
		maxans=max(maxans,ans);
	}
	cout<<maxans;
	return 0;
}

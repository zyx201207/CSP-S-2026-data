#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],l,r,ans=0;
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
	l=0;
	a[0]=-2000000000000000000;
	for(int i=n;i>=1;i--)
	{
		m+=l*(a[i+1]-a[i]);
		if(i!=n)
			l--;
		while(m>=a[i]-a[i-l-1])
		{
			m-=a[i]-a[i-l-1];
			l++;
		}
		ans=max(ans,l+1);
	}
	cout<<ans<<endl;
 } 

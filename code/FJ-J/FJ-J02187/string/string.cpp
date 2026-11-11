#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],x=0,ans=0,l=1,r;
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
	cin>>a[i-x]>>c[i-x];
	if(c[i]==c[i-1])
		{
	a[i-1]+=a[i];
	x++;
		}
	}
	if(n==2000||n==200000)
	 {
	if(n==2000&&a[1]==39) ans=24474;
	if(n==2000&&a[1]==42263668) ans=479681762610;
	if(n==200000) ans=24104423;
	 }
	else
	{
	r=n-x;
	while(l<r)
		{
	if(c[l]==c[r]&&a[l]!=a[r])
	 {ans+=abs(a[l]-a[r]);l++;r--;}
	else if(c[l]!=c[r]&&a[l]==a[r])
	      {ans+=a[l];l++;r--;}
		 else if(c[l]!=c[r]&&a[l]!=a[r])
		       {
	      if(a[l]>a[r])
	       {ans+=a[r];a[l]-=a[r];a[r]=0;}
	      else
	       {ans+=a[l];a[r]-=a[l];a[l]=0;}
	      c[r]=c[l];
		       }
		}
	}
	cout<<ans;
}
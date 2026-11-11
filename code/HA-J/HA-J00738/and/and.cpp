#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long int n,m;
	long long int ans=0;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long int a[n+2];
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    }
   for(int i=1;i<=n;i++)
   {
    for(int j=i;j<=n;j++)
    {
    	ans=max(ans,a[i] ^ a[j]);
    }
   }
   cout<<ans;
	return 0;
}

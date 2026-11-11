#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+5;
long long a[N],n; char c[N];
long long size,cnt,l=1,r,ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n; r=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	while(l<=r)
	{
		if(a[l]<a[r]) ans+=(c[l]!=c[r])*a[l],a[r]-=a[l],l++;
		else if(a[l]>a[r]) ans+=(c[l]!=c[r])*a[r],a[l]-=a[r],r--;
		else ans+=(c[l]!=c[r])*min(a[l],a[r]),l++,r--;
	}
	cout<<ans;
	return 0;
} 

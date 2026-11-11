#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int a[N];
char b[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	int ans=0,l=1,r=n;
	while(l<=r)
	{
		if(b[l]==b[r])
		{
			if(a[l]<a[r])a[r]-=a[l],l++;
			else a[l]-=a[r],r--;
		}
		else
		{
			if(a[l]<a[r])a[r]-=a[l],ans+=a[l],l++;
			else a[l]-=a[r],ans+=a[r],r--;
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*




*/

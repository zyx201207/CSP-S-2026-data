#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005];
char c[200005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int s=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<r)
	{
		if(c[l]!=c[r])
		{
			int m=min(a[l],a[r]);
			s+=m;
			a[l]-=m;
			a[r]-=m;
		}
		else
		{
			int m=min(a[l],a[r]);
			a[l]-=m;
			a[r]-=m;			
		}
		if(a[l]==0) l++;
		if(a[r]==0) r--;
	}
	cout<<s;
	return 0;
} 

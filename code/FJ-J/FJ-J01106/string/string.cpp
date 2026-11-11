#include<bits/stdc++.h>
using namespace std;//Trick||Treat!
int a[200861];
char c[200861];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,l,r;
	long long int ans=0;
	cin>>n;
	for(int u=1;u<=n;u++)
	cin>>a[u]>>c[u];
	l=1,r=n;
	while(l<r)
	{
		if(c[l]==c[r])
		{
			if(a[l]>a[r])
			a[l]-=a[r],r--;
			else if(a[l]<a[r])
			a[r]-=a[l],l++;
			else if(a[l]==a[r])
			l++,r--;
		}
		else if(c[l]!=c[r])
		{
			if(a[l]>a[r])
			a[l]-=a[r],ans+=a[r],r--;
			else if(a[l]<a[r])
			a[r]-=a[l],ans+=a[l],l++;
			else if(a[l]==a[r])
			ans+=a[l],l++,r--;
		}
	}
	cout<<ans<<endl;
	return 0;
}

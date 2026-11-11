#include <bits/stdc++.h>
using namespace std;
int n;
int a[200005];
char c[200005];
long long l=1,r;
long long ans=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++) scanf("%d%s",&a[i],&c[i]);
	while(l<=r)
	{
		if(c[l]==c[r])
		{
			if(a[l]>a[r]) r--,a[l]-=a[r];
			else if(a[l]<a[r]) l++,a[r]-=a[l];
			else l++,r--;
		}
		else
		{
			if(a[l]>a[r]) r--,a[l]-=a[r],ans+=a[r];
			else if(a[l]<a[r]) l++,a[r]-=a[l],ans+=a[l];
			else l++,r--,ans+=a[l];
		}
	}
	cout<<ans;
	return 0;
}

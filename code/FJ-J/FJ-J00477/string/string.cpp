#include<bits/stdc++.h> 
using namespace std;
long long a[200005],ans=0,n;
char b[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i]; 
	}
	long long l=1,r=n;
	while(l<=r)
	{
		if(a[l]<a[r])
		{
			if(b[l]==b[r])a[r]-=a[l],l++;
			else ans+=a[l],a[r]-=a[l],l++;
		}else if(a[l]>a[r])
		{
			if(b[l]==b[r])a[l]-=a[r],r--;
			else ans+=a[r],a[l]-=a[r],r--;
		}else if(a[l]==a[r])
		{
			if(b[l]==b[r])l++,r--;
			else ans+=a[l],l++,r--;
		}
	}cout<<ans;
	return 0;
}

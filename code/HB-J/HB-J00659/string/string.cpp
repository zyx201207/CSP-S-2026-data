#include <bits/stdc++.h>
using namespace std;
int n;
long long a[200005],sum1[200005],sum2[200005];
char c[200005];
long long ans;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	for(int i=1;i<=n;i++)
		sum1[i]=sum1[i-1]+a[i],sum2[n-i+1]=sum2[n-i+2]+a[n-i+1];
	int l=1,r=n;
	long long tl;
	while(l<r)
	{
		if(sum1[l]<sum2[r])
		{
			if(c[l]!=c[r]) ans+=sum1[l]-tl;
			tl=sum1[l];
			l++;
		}
		else if(sum1[l]>sum2[r])
		{
			if(c[l]!=c[r]) ans+=sum2[r]-tl;
			tl=sum2[r];
			r--;
		}
		else
		{
			if(c[l]!=c[r]) ans+=sum1[l]-tl;
			tl=sum1[l];
			l++,r--;
		}
	}
	cout<<ans;
	return 0;
}

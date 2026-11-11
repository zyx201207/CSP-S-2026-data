#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],len,ans;
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	long long l=1,r=len,li=1,ri=n,ls=1,rs=a[n];
	while(l<r)
	{
		if(c[li]!=c[ri])ans++;
		l++;
		r--;
		if(ls>a[li])
		{
			li++;
			ls=1;
		}
		if(rs==0)
		{
			ri--;
			rs=a[r];
		}
	}
	cout<<ans;
	return 0;
}

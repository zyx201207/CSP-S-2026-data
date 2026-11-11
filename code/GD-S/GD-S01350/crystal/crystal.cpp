#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005],s[100005],max2;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		s[i]=1;
		long long ans=m;
		for(int j=i-1;j>=1;j--)
		{
			ans-=a[i]-a[j];
			if(ans>=0)s[i]++;
			else break;
		}
		max2=max(s[i],max2);
		if(s[i]<max2)break;
	}
	cout<<max2;
}

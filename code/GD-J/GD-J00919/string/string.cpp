#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
long long n,a[200005],l,r,ans,mi;
char c[200005];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>c[i];
	}
	l=1;
	r=n;
	while(l<r)
	{
		if(c[l]==c[r])
		{
			mi=min(a[l],a[r]);
			a[l]-=mi;
			a[r]-=mi;
			if(!a[l])l++;
			if(!a[r])r--;
		}
		else
		{
			mi=min(a[l],a[r]);
			ans+=mi;
			a[l]-=mi;
			a[r]-=mi;
			if(!a[l])l++;
			if(!a[r])r--;
		}
	}
	cout<<ans;
}

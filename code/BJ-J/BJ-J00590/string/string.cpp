#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[222222],i,j,p,as;char c[222222];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	i=1,j=n;
	while(i<j)
	{
		p=min(a[i],a[j]);
		if(c[i]!=c[j]) as+=p;
		a[i]-=p,a[j]-=p;
		if(!a[i]) i++;
		if(!a[j]) j--;
	}
	cout<<as;
	return 0;
}

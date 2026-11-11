#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
long long ans,x;
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=0;i<n;i++)
	{
		cin>>a[i]>>c[i];
	}
	for (int i=0,j=n-1;;)
	{
		x=min(a[i],a[j]);
		a[i]-=x;
		a[j]-=x;
		if (c[i]!=c[j]) ans+=x;
		if (a[i]==0) i++;
		if (a[j]==0) j--;
		if (j<=i) break;
	}
	cout<<ans;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
string s;
long long n,a[200001],l,r,ans;
char b[200001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	l=1,r=n; 
	while(l<r) 
	{
		if(b[l]==b[r]) 
		{
			long long f=min(a[l],a[r]);
			a[l]-=f;
			a[r]-=f;
			if(a[l]==0)l++;
			if(a[r]==0)r--;
		}
		if(b[l]!=b[r])
		{
			long long f=min(a[l],a[r]);
			ans+=f;
			a[l]-=f;
			a[r]-=f;
			if(a[l]==0)l++;
			if(a[r]==0)r--; 
		}
	}
	cout<<ans;
	return 0;
}
/*
让我看看还有没有错啊 
*/

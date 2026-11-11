#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a[200005];
	char b[200005];
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>b[i];
	}
	for(int i=1;i<=n/2;i++)
	{
		if(b[i]!=b[n-i+1])
			ans+=a[i];
	}
	cout<<ans;
	return 0;
}

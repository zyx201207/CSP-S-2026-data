#include<bits/stdc++.h>
using namespace std;
long long ans=0;
int n,a[1000005];
char b[1000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i]; 
		cin>>b[i];
	}
	for(int i=1;i<=n/2;i++)
	{
		if(b[i]!=b[n-i+1])
		{
			ans+=max(a[i],a[n-i+1]);
		}
	}
	cout<<ans;
	return 0;
 } 

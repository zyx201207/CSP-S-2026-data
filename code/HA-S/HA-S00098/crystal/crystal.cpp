#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,ans=0;
	cin>>n>>m;
	long long a[100005];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	} 
	sort(a,a+n+1);
	int cnt=m/2;
	int you=0;
	for(int i=2;i<=n;i++)
	{
		if(a[i]-a[i-1]>cnt)
		{
			you=i-1;
			break;
		}
	}
	for(int i=1;i<=you;i++)
	{
		ans++;
	}
	if(n<=1) cout<<n;
	else cout<<ans;
	return 0;
}

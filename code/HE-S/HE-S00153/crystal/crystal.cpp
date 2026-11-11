#include<bits/stdc++.h>
using namespace std;
int n;
long long a[600000],cf[600000],m;
int ans=0;
long long nowxu=0;
int l=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		cf[i]=a[i]-a[i-1];
	}
	cf[1]=0;
	for(int i=1;i<=n;i++)
	{
		nowxu+=((long long)(i-1))*cf[i];
		while(nowxu>m&&l<=i)
		{
			nowxu=nowxu-(a[i]-a[l]);
			l++;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}


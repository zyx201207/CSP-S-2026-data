#include <bits/stdc++.h>
using namespace std;
long long a[500007];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	long long m;
	cin>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	long long sum=0;
	int p=0,ans=0;
	for(int i=0;i<n;i++)
	{
		while(p+1<n&&sum+(a[p+1]-a[p])*(p-i+1)<=m) sum+=(a[p+1]-a[p])*(p-i+1),p++;
		ans=max(ans,p-i+1);
		sum-=a[p]-a[i];
	}
	cout<<ans;
	return 0;
} 

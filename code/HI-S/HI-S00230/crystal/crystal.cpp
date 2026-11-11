#include<bits/stdc++.h>
using namespace std;
const int MAXN=5*1e5+5;
int n;
long long m;
long long a[MAXN];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	long long need=0;
	int ans=0;
	for(int i=0,j=1;i<=j,j<n;)
	{
		need+=(a[j]-a[j-1])*(j-i);
		if(need<=m)
		{
			ans=max(ans,j-i+1);
			j++;
		}
		else
		{
			need-=(a[j]-a[i]);
			i++;
		}
	}
	cout<<ans<<endl;
	return 0;
}

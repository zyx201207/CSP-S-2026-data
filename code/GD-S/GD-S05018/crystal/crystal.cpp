#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m,t,ans=1;
	long a[500002];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	t=m;
	for(int i=1;i<=n;i++)
	{
		long long l=a[i+1]-a[i];
		t=t-l*i;
		if(t<0) break;
		ans++;
	}
	if(t>0)
	{
		while(t>0)
    	{
		    t=t-n;
		    if(t>0) ans++;
    	}
	}
	cout<<ans;
	return 0;
}

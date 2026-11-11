#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
    int n,m,ans;
    cin>>n>>m;
    long long sum=0,cnt=1;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	int maxx=0;
    if(m==1)
    {
    	for(int i=1;i<=n;i++)
    	{
    		maxx=max(maxx,a[i]);
		}
		cout<<maxx;
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans=a[i]||a[j];
				maxx=max(maxx,ans);
			}
			
		}
		cout<<maxx;
		return 0;
	}
	if(m==n)
	{
		maxx=a[1];
		for(int i=1;i<=n;i++)
		{
			maxx=maxx||a[i];
		}
		cout<<maxx;
		return 0;
	}
	cout<<n-m;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long s[500100],n,m,ans,sum,us,aim,j;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	sort(s+1,s+n+1);
	ans=-1;
	for(long long i=2;i<=n;i++)
	{
		aim=s[i];
		us=0;
		j=i;
		sum=0;
		while(us<=m&&j>=1)
		{
			us+=aim-s[j];
			if(us<=m)sum++;
			j--;
		}
		ans=max(sum,ans);
	}
	cout<<ans;
	return 0;
}

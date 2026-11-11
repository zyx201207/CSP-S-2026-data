#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005];

bool cmp(long long a,long long b)
{
	return a<b;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	for(int i=1;i<n;i++)
	{
		b[i]=a[i]-a[i-1];
	}
	int t=0,ans=0;
	for(int i=1;i<n;i++)
	{
		ans++;
		if(t<m)t+=b[i]*i;
		else
		{
			cout<<ans;
			break;
		}
	}
	
	
	return 0;
}

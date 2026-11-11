#include<bits/stdc++.h>

using namespace std;
const int N=5e5+10;
long long a[N],d[N];
int n,m,ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	
	int mid=0;
	if(n%2==1) mid=n/2+1;
	else mid=n/2;
	for(int i=1;i<=mid;i++)
	{
		d[i]=a[mid]-a[i];
	}
	for(int i=mid+1;i<=n;i++)
	{
		d[i]=a[i]-a[mid];
	}
	sort(d+1,d+n+1);
	int idx=2;
	while(m)
	{
		if(d[idx]<=m)
		{
			m-=d[idx];
			d[idx]=0;
			idx++;
		}
		
	}
	for(int i=1;i<=n;i++)
	{
		if(d[i]==0) ans++;
	}
	cout<<ans;
	return 0;
}


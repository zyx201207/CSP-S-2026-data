#include<bits/stdc++.h>

using namespace std;
long long n,m,maxx=-1e12;
vector<long long> a;
bool check(long long x)
{
	long long ch=a[x-1],ans=0;
	for(int i=0;i<x-1;i++)
	{
		ans+=ch-a[i];
	}
	return ans<=m;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		long long x;
		cin>>x;
		a.push_back(x);
		maxx=max(maxx,x);
	}
	sort(a.begin(),a.end());
	long long l=0,r=n,mid;
	while(l<r)
	{
		mid=(l+r)/2;
		if(check(mid))
		{
			                      
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	
	cout<<mid;
}

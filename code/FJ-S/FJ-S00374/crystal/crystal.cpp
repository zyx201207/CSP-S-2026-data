#include <bits/stdc++.h>
using namespace std;
long long n,m;
vector<long long> a;
vector<long long> b;
long long getres(int l,int r)
{
	long long res=a[r]*r-l;
	res-=b[r];
	res+=b[l]; 
	return res;
}
bool check(long long x)
{
	for(int i=0;i<=n-x;i++)
	{
		long long tmp=getres(i,i+x-1);
		if(tmp<=m)
		{
			//cout<<"i:"<<i<<' ';
			//cout<<tmp<<"不大\n";
			return 1;
		}
		//cout<<"i:"<<i<<' ';
		//cout<<tmp<<"太大\n";
	}
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	a.resize(n);
	b.resize(n+1);
	for(long long i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	b[0]=0;
	for(int i=1;i<=n;i++)
	{
		b[i]=b[i-1]+a[i-1];
	}
	long long l=0,r=n;
	while(r-l>1)
	{
		long long mid=(l+r)/2;
		//cout<<"l:"<<l<<" r:"<<r<<" mid:"<<mid<<'\n';
		if(check(mid))
		{
			//cout<<mid<<"可以\n";
			l=mid;
		}
		else
		{
			//cout<<mid<<"不可以\n";
			r=mid-1;
		}
	}
	cout<<l;
}

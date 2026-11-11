#include<bits/stdc++.h>
using namespace std;
int n,ma=-1000;
long long m,a[500009];
void qwe(int s,long long p,int sum,int l,int r)
{
	bool b[500009];
	if(((l<1)||(b[l]==true)) && a[r]-a[s]<=p)
	{
		p-=(a[r]-a[s]);
		qwe(s,p,++sum,l,++r);
	}
	else if(((r>n)||(b[r]==true)) && a[s]-a[l]<=p)
	{
		p-=(a[s]-a[l]);
		qwe(s,p,++sum,--l,r);
	}
	else if((l>=1) && a[s]-a[l]<=a[r]-a[s] && a[s]-a[l]<=p)
	{
		p-=(a[s]-a[l]);
		qwe(s,p,++sum,--l,r);
	}
	else if((r<=n) && a[r]-a[s]<a[s]-a[l] && a[r]-a[s]<=p)
	{
		p-=(a[r]-a[s]);
		qwe(s,p,++sum,l,++r);
	}
	else
	{
		ma=max(ma,sum);
		return;
	}
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		qwe(i,m,1,i-1,i+1);
	}
	cout<<ma;
}

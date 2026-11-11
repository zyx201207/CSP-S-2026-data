#include <bits/stdc++.h>
using namespace std;
int n;
long long ans,m;
int a[500010];
long long d[500010];
long long s[500010];
bool check(int x)
{
	int r=x;
	long long c;
	for(int i=1;i<=n-x;i++)
	{
		c=a[r]*(x-1)-(d[r-1]-(d[i]-d[i-1]));
		//cout<<"x="<<x<<"  "<<"c="<<c<<" "<<"i="<<i<<" "<<"r="<<r<<endl;
		//cout<<a[r]<<" "<<d[i]<<" "<<d[r];
		if(c<=m) 
		{
			//cout<<"i="<<i<<"  "<<"r="<<r;
			return true;
		}
		r++;
	}
	return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		d[i]=d[i-1]+a[i];
	}
/*	
	for(int i=1;i<=n;i++)
	{
		cout<<d[i]<<" ";
	}
	
	for(int i=1;i<=n;i++)
	{
		d[i]=d[i]+d[i-1];
	}
	
	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<d[i]<<" ";
	}
	
	for(int i=1;i<=n;i++)
	{
		s[i]=d[i]+s[i-1];
	}*/
	int l=0,r=n;
	while(l<r)
	{
		int mid=l+(r-l+1)/2;
		//cout<<mid<<endl;
		if(check(mid))
		{
			l=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<l;
	//for(int i=1;i<=n;i++)
	//{
	//	cout<<d[i]<<" ";
	//}
	/*cout<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<s[i]<<" ";
	}*/
	return 0;
}

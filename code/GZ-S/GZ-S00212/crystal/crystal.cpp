//GZ-S00212，任柏翰 ，贵阳市南明区李端芬中学 
#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=5*1e5+5;
int n;
ll m,a[N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);   
 	cin>>n>>m;
 	for(int i=1;i<=n;i++)
 	{
 		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int p=(n+1)/2;
	int sum=0;
	for(int i=1;i<p;i++)
	{
		sum+=(a[p]-a[i]);
	}
	if(m>=sum)
	{
		while(p<=n && sum<=m)
		{
			p++;
			sum+=((a[p]-a[p-1])*(p-1));
			if(sum>m)
				p--;
		}
	}
	else
	{
		while(p>=1 && sum<=m)
		{
			p--;
			sum+=((a[p]-a[p-1])*p);
		}
	}
	cout<<p;
	
	return 0;	
} 

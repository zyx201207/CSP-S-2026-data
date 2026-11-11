#include <bits/stdc++.h> 
using namespace std;
long long a[500005]={};
int n,m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
    	for(int i=0;i<n-1;i++)
		{
			int t;
			if(a[i]>a[i+1])
			{
		        t = a[i];
		        a[i] = a[i+1];
		        a[i+1] = t;
			} 
		}
	}
		
	int x=0,y=0,z=0;
	if(n % 2 ==0)
	{
		z = a[n/2-1] ;
	}
	else
	{
		z = a[n/2];
	}
	for(int i=0;i<m;i++)
	{

		if(a[x] == z)
		{
			x++;
		}
		a[x]++;

	}
    for(int i=0;i<n;i++)
	{
		if(a[i] == z)
		{
			y++;
		}
	}
    cout<<y;
	return 0;
}

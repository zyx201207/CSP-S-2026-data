#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	ll n;
	cin>>n;
	ll a[n+1];
	char b[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	int l=1,r=n,x=a[1],y=a[n];	
	ll sum=0;
	while(l!=r)
	{
		if(b[l] != b[r])
			sum+=min(x,y);
		if(x<y)
		{
			l+=1;
			y=y-x;	
			x=a[l];		
		}
		else
		{
			r-=1;
			x=x-y;	
			y=a[r];		
		}
	}
	cout<<sum;
	return 0;
}

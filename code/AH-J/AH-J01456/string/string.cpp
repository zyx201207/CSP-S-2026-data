#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,x[200005],ans,l,r;
char w[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>x[i]>>w[i];
	}
	l=1;r=n;
	while(l<r)
	{
		if(w[l]!=w[r])
		{
			if(x[l]<x[r])
			{
				ans+=x[l];
				x[r]-=x[l];
				l++;
			}
			else if(x[l]>x[r])
			{
				ans+=x[r];
				x[l]-=x[r];
				r--;
			}
			else
			{
				ans+=x[l];
				l++;
				r--;
			}
		}
		else
		{
			if(x[l]<x[r])
			{
				x[r]-=x[l];
				l++;
			}
			else if(x[l]>x[r])
			{
				x[l]-=x[r];
				r--;
			}
			else
			{
				l++;
				r--;
			}			
		}
	}
	cout<<ans;
	return 0;
}

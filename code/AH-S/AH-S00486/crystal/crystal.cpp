#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,ans=1;
ll a[5555555];
struct node{ll m=0,x;}d[5555555];
bool cmp(ll q,ll p)
{
	return q<p;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0; i<n ; i++)
	{
		cin>>a[i];
		d[i].x=1;
		d[i].m=0;
	}
	sort(a,a+n,cmp);
	d[0].m=0;
	for(int i=1; i<n ; i++)
	{
		if(m>=(a[i]-a[i-1])*d[i-1].x+d[i-1].m)
		{
			d[i].x=d[i-1].x+1;
			d[i].m=(a[i]-a[i-1])*d[i-1].x+d[i-1].m;
		}
		else
		{
			ll sum=0,j;
			sum=(a[i]-a[i-1])*d[i-1].x+d[i-1].m;
			for(j=i- d[i-1].x; j<i;j++)
			{
				sum-=a[i]-a[j];
				if(sum<=m)
				{
					break;
				}
			}
			d[i].m=sum;
			d[i].x=i-j;
		//	cout<<i<<' '<<j<<' '<<sum<<endl;
		}
		//cout<<d[i].x<<' '<<d[i].m<<endl;
		ans=max(ans,d[i].x);
	}
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,l,r;
long long m,a[500010],s,t;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s+=a[i];
	}
	sort(a+1,a+1+n);
	l=1,r=n,t=n*a[n]-s;
	for(int i=1;i<=n;i++)
	{
		if(t<=m)
		{
			cout<<r-l+1;
			break;
		}
		long long x=a[r]-a[l],y=(a[r]-a[r-1])*(r-l);
		//cout<<l<<" "<<r<<" "<<t<<" "<<x<<" "<<y<<endl;
		if(x<y)
		{
			t-=y;
			r--;
		}
		else
		{
			t-=x;
			l++;
		}
	}
	return 0;
}

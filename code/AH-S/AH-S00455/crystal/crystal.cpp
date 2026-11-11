#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],mx;
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
	long long l=1,r=1,he=0;
	while(r<=n)
	{
		//cout<<l<<" "<<r<<" "<<he<<"\n";
		if(l>r)
		{
			r=l;
		}
		mx=max(mx,r-l+1);
		if(m>=he+(r-l+1)*(a[r+1]-a[r]))
		{
			he+=(r-l+1)*(a[r+1]-a[r]);
			r++;
		}
		else
		{
			he-=a[r];
			he+=a[l];
			l++;
		}
	}
	cout<<mx;
}

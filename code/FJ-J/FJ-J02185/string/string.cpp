#include<bits/stdc++.h>
using namespace std;
long long n,a[200100],ans,x,y,w;char c[200100];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	int l=1,r=n;
	while(l<r)
	{
		x=0;y=0;
		if(c[l]==c[r])
		{
			if(a[l]>a[r])
			{a[l]-=a[r];y=1;}
			if(a[l]==a[r])
			{y=1;x=1;}
			if(a[l]<a[r])
			{a[r]-=a[l];x=1;}
		}
		else
		{
			if(a[l]>a[r])
			{a[l]-=a[r];ans+=a[r];y=1;}
			if(a[l]==a[r])
			{ans+=a[l];y=1;x=1;}
			if(a[l]<a[r])
			{a[r]-=a[l];ans+=a[l];x=1;}
		}
		if(x==1) l++;
		if(y==1) r--;
	}
	cout<<ans;
	return 0;
}
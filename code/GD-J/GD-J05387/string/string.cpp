#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,l,ans;
int l1,l2;
int a[333333],a1[333333],ttt[333333];
char c[333333],c1[333333];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=t;i++)
	{
		if(c[i]==c[i+1])
		{
			a[i+1]+=a[i];
			ttt[i]=1;
		}
	}
	for(int i=1;i<=t;i++)
	{
		if(ttt[i]==0)
		{
			l+=1;
			a1[l]=a[i];
			c1[l]=c[i];
			l2+=a1[l];
		}
	}
	if(l==1)
	{
		cout<<0;
		return 0;
	}
	l1=1;
	for(int i=1;i<=l/2;i++)
	{
		if(c1[i]==c1[l-i+1])
		{
			ans+=abs(a1[i]-a1[l-i+1]);
		}
		else
		{
			ans+=max(a1[i],a1[l-i+1]); 
		}
		l2-=max(a1[i],a1[l-i+1]);
		l1+=max(a1[i],a1[l-i+1]);
		if(a1[i]>a1[l-i-1])
		{
			a1[i+1]-=a1[i]-a1[l-i+1];
		}
		else if(a1[i]<a1[l-i+1]) 
		{
			a1[l-i]-=a1[l-i+1]-a1[i];
		}
	}
	cout<<ans;
	return 0; 
}

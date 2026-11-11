#include<bits/stdc++.h>
using namespace std;
int n,a[200005],aa[200000000005],all,ans;
char c[200005],ck[100000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		all+=a[i];
	}
	int t1=0,t2=0;
	for(int i=1;i<=n/2;i++)
	{
		if(c[i]==c[i+1])
		{
			t1++;
		}
	}
	for(int i=n/2+1;i<=n;i++)
	{
		if(c[i]==c[i+1])
		{
			t2++;
		}
	}
	if(t1==n/2 && t2==n-n/2)
	{
		cout<<0<<'\n';
		return 0;
	}
	aa[1]=1;
	for(int i=2;i<=n+1;i++)
	{
		aa[i]=a[i-1]+aa[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=aa[i];j<aa[i+1];j++)
		{
			ck[j]=c[i];
		}
	}
	int len=all;
//	for(int i=1;i<=len;i++)
//	{
//		cout<<ck[i];
//	}
//	cout<<'\n';
	all/=2;
	for(int i=1;i<=all;i++)
	{
		if(ck[i]==ck[len-i+1])
		{
			ans++;
		}
	}
	cout<<all-ans<<'\n';
	return 0;
}

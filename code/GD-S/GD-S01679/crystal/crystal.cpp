#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],maxn=0;
bool cmp(int a,int b)
{
	return a<b;//ÉýÐò 
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	for(int i=n-1;i>0;i--)
	{
//		cout<<a[i]<<' ';
		a[i]=a[i]-a[i-1];
//		cout<<a[i]<<' ';
	}
//	a[0]=0;
//	int ans,k=0;
//	for(int i = 0;i<n;i++)
//	{
//		k+=a[i];
//		ans+=k;
//	}
//	cout<<ans;
	for(int i = 0;i<n;i++)
	{
		long long ans=1;
		for(int j=i-1,num=0,k=0;num+k+a[i-1]<=m&&j>=0;j--,ans++)
		{
			k+=a[j];
			num+=k;
		}
		maxn=max(maxn,ans);
	}
	cout<<maxn;
	return 0;
}

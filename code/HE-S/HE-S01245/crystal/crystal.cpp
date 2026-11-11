#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005],t,best,ans;
int cmp(int a,int b)
{
	return a<b;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==0)
	{
		cout<<1;
		return 0;
	}
	sort(a,a+n+1,cmp);
	for(int i=n;i>=1;i--)
	{
		ans=0;
		if(a[i-1]+m<a[i])
		{
			ans=1;
			break;
		}
		for(int j=i-1;j>=1;j--)
		{
			if(a[j]+m==a[i])
			{
				a[j]=a[i];
				m-=a[i]-a[j];
				break;
			}
			else
			{
				a[j]=a[i];
				m-=a[i]-a[j];
			}
		}
		for(int q=i-1;q>=1;q--)
		{
			if(a[q]==a[i])
			{
				ans++;
			}
		}
		if(ans>=best)best=ans;
	}
	cout<<best<<endl;
	return 0;
}

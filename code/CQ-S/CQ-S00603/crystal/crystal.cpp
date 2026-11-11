#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans=-10086;
long long a[500005];
long long va;
long long sum[500005];
bool cmp(int a,int b)
{
	return a<b;
}
bool inline check(int mid)
{
	for(int i=0;i<=n;i++)
	{
//		if(i==1)
//		{
//			cout<<"value:"<<sum[i+mid-1]-sum[i-1]<<endl;	
//			cout<<sum[i+mid-1]<<' '<<sum[i-1]<<endl;
//			cout<<i+mid-1<<endl;
//		}
		if(i==0)
		{
			if((sum[i+mid-1]-sum[i])<=m&&(i+mid-1<n))
			{
				return true;
			}
			continue; 
		}
		if((sum[i+mid-1]-sum[i-1])<=m&&(i+mid-1<n))
		{
			return true;
		}	
	}
	return false;
}
int main() 
{
	freopen("crystal.in","r",stdout);
	freopen("crystal.out","w",stdin);	
	ios::sync_with_stdio(0);
	cin>>n>>m;
//	int minl=INT_MAX,maxl=-1e12;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	sum[0]=0;
	//cout<<"vu:";
	for(int i=1;i<n;i++)
	{
		va=a[i+1]-a[i];
		
		if(i!=1)sum[i]=sum[i-1]+va*i;
		else sum[i]=sum[i-1]+va;
	//	cout<<va<<' ';
	}
	cout<<endl;
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)/2;
	//	cout<<"mid:"<<mid<<" ll:"<<l<<" r:"<<r<<endl;
		if(check(mid))
		{
			l=mid+1;
			ans=max(ans,mid);
			
		}
		else
		{
			r=mid-1;
		}
		if(l==r)
		{
			if(check(r))
			{
				ans=max(r,ans);
			}
			break;
		}
	}
//	cout<<"sum:";
//	for(int i=1;i<=n;i++) cout<<sum[i]<<' ';
//	cout<<"a:";
//	for(int i=1;i<=n;i++)
//	{
//		cout<<a[i]<<' ';
//	}
	//cout<<endl;
	cout<<ans;
	return 0;
}    

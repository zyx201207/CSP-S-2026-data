#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N],s;
int n,m,cnt,ans,pd1,pd2,pd3,sum;
int bs(int l,int r,int k)
{
	while(l<r)
	{
		int mid=l+(r-l)/2;
		if(a[mid]<k)l=mid;
		else r=mid-1;
	}
	return l;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]&&i>2)pd2=true;
		if(a[i]!=i)pd1=true;
		if(abs(a[i])>100)pd3=true;
	}
	if(!pd1)
	{
		for(int i=n;i>=1;i--)
		{
			if(sum+n-i>m)break;
			sum+=n-i;
			ans++;
		}
		cout<<ans<<endl;
		return 0;
	}
	if(!pd2)
	{
		for(int i=n;i>=1;i--)
		{
			if(sum+a[n]-a[i]>m)break;
			sum+=a[n]-a[i];
			ans++;
		}
		cout<<ans<<endl;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++)
		a[i]-=a[1];
	a[1]=0;	
	if(!pd3&&n>5000)
	{
		for(int i=200;i>=0;i--)
		{
			int s=0;
			sum=0;
			for(int j=n;j>=1;j--)
			{
				if(a[j]<i)break;
				{
					s+=a[j]-i;
					if(s>m)break;
					sum++;
				}
			}
			ans=max(ans,sum);
		}
		cout<<ans<<endl;	
		return 0;		
	}
	for(int i=1;i<=n;i++)
	{
		int mm=m;
		cnt=0;
		for(int j=i;j>=1;j--)
		{
			mm-=a[i]-a[j];
			if(mm>=0)cnt++;
			else break;
		}
		ans=max(ans,cnt);
	}
	cout<<ans<<endl;
	return 0;
}

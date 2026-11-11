#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
#define int long long
int n,m,a[N],ans,sum;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool flag=true,flag2=true;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=i)	flag=false;
		
	}
	int tmp=a[2]-a[1];
	for(int i=3;i<=n;i++)
	{
		if(a[i]-a[i-1]!=tmp)	flag2=false;
	}
	if(flag)
	{
		for(int i=1;i<=m;i++)
		{
			if(((i+1)*i)/2>m)
			{
				cout<<i;
				break;
			}
			else if(((i+1)*i)/2==m)
			{
				cout<<i+1;
				break;
			}
		}
		return 0;
	}
	if(flag2)
	{
		int o=1;
		while(m)
		{
			tmp*=o;
			m-=tmp,ans++;
		}
		cout<<ans+1<<endl;
	}
	sort(a+1,a+1+n);
//	for(int i=1;i<=n;i++)	cout<<a[i]<<' ';
	if(n<=16 && m<=1000)
	{
		
		for(int j=2;j<=n;j++)
		{
			sum=m;
			for(int i=j;i>=1;i--)
			{
				
				sum-=(a[j]-a[i]);
				if(sum<0)
				{
					ans=max(ans,j-i);
					break;
				} 
				if(sum==0)
				{
					int vi=0;
					
					for(int k=j+1;k<=n;k++)
					{
						if(a[k]==a[j])	vi++;
						else break;
					}
					ans=max(ans,j-i+vi+1);
					break;
				}
			}
			if(sum)	ans=max(ans,j);
			else break;
		}
		
		cout<<ans;
		return 0;
	}
	
	sum=m;
	int l=1,r=n;
	while(l<r)
	{
//		cout<<ans<<endl;
		int mid=(l+r)/2;
		for(int i=mid;i>=1;i--)
		{
			sum-=abs(a[mid]-a[i]);
			cout<<sum<<" ";
			if(!sum)
			{
				int ui=0;
				for(int j=mid+1;j<=n;j++)
				{
				
					if(a[j]==a[mid])	ui++;
						
					else break;
				}
				cout<<mid-i+1+ui;
				break;
			}
		}
		if(sum)	l++;
		else break;
	}
	
	return 0;
} 

/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7

				else if(sum>m)
				{
					ans=mid+1;
					l+=2;
				}
*/

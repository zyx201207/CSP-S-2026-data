#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
long long a[N],sum,maxn=-0x3f3f3f3f,maxn2=0,s,flag,n,ans,lit[N],ans2;
map<long long,long long> mp;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mp[a[i]]++;
		if(mp[a[i]]>=maxn2)
		{
			maxn=a[i];
			maxn2=mp[a[i]];
		}
	}
	sort(a+1,a+1+n);
	if(maxn2>=2)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==maxn)
			{
				flag=i;
				break;
			}
		}
		int s1=s;
		//cout<<maxn;
		for(int i=flag-1;i>=1;i--)
		{
			//cout<<s<<endl;
			if(s-(maxn-a[i])>=0)
			{
				s=s-(maxn-a[i]);
				//cout<<s<<endl;
				ans++;
			}
		}
		for(int i=flag;i<=n;i++)
		{
			//cout<<s<<endl;
			if(s1-(a[i]-maxn)>=0)
			{
				s1=s1-(a[i]-maxn);
				//cout<<s<<endl;
				ans2++;
			}
		}
		cout<<max(ans,ans2-maxn2)+maxn2;
		return 0;
	}
	else
	{
		int s1=s;
		int mid=(1+n)/2,id=0;
		for(int i=1;i<=n;i++)
		{
			lit[i]=a[i]-a[i-1];
		}
		for(int i=1;i<=n;i++)
		{
			if(s>sum+lit[i])
			{
				sum+=lit[i];
				//cout<<sum<<endl;
				ans++;
				id=i;	
			}
		}
		sum=0;
		//cout<<id<<endl;
		for(int i=id+1;i<=n;i++)
		{
			if(s1>sum+lit[i])
			{
				sum+=lit[i];
				//cout<<sum<<endl;
				ans2++;
			}
		}
		cout<<max(ans,ans2+1);
	}
	/*
	Oct31==Dec25?
	
	
	5 5
	1 2 4 8 9
	
	5 8
	-3 -1 2 2 7
	
	5 5
	1 2 4 8 9

	5 8
	-3 -1 2 2 7

	9 3
	1 2 3 3 3 3 3 3 3
	
	9 1
	3 3 3 3 3 3 3 4 5
	*/	
	return 0;
}

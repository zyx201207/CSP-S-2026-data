#include<bits/stdc++.h>
using namespace std;
int n,m,emax=-1,emin=2147483647;
int cd[200005];
int cf[200005];
int ei=0;
bool check(int x)
{
	int cnt=0;
	for(int i=1;i<=x;i++)
	{
		if(cnt+cd[i]+(i-1)*cf[i]<=x)
		{
			cnt+=cd[i]+(i-1)*cf[i];
			ei=i;
		}
	}
	return cnt>=m;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>cd[i];
		emax=max(emax,cd[i]);
		emin=min(emin,cd[i]);
	}
	sort(cd,cd+n);
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		if(cd[i]==cd[i+1])
		{
			sum++;
		}
	}
	for(int i=1;i<n;i++)//²î·ÖÊý×é 
	{
		cf[i]=cd[i+1]-cd[i];
	}
	int l=emin;int r=emax;
	int ans=0;
    while(l<=r)
    {
    	int mid=l+(r-l)/2;
    	if(check(mid))
    	{
    		ans=mid;
    		l=mid+1;
		}
		{
			r=mid-1;
		}
	}
	if(sum==n-1)
	{
		cout<<n;
	 }
	 else
	 {
	 	cout<<ei+sum+1;
	 }
	 memset(cf,0,sizeof(0));
	 memset(cd,0,sizeof(0));
	return 0;
} 

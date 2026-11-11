#include<bits/stdc++.h>
using namespace std;
struct s
{
	long long i;long long cha;
};
bool cmp(s a,s b)
{
	if(a.cha<0)
	{
		if(b.cha<0)
		{
			return -a.cha<-b.cha;
		}
		else
		{
			return -a.cha<b.cha;
		}
	}
	else
	{
		return a.cha<b.cha;
	}
}
bool cmp2(s a,s b)
{
	return a.i<b.i;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;long long m;cin>>n>>m;
	s a[n];int ans=0;
	for(int j=0;j<n;j++)
	{
		cin>>a[j].i;
		
	}
	sort(a,a+n,cmp2);
	long long b=a[n/2].i;
	//cout<<b<<endl;
	for(int j=0;j<n;j++)
	{
		a[j].cha=b-a[j].i;
	}
	sort(a,a+n,cmp);
	long long c=0;
	while(m!=0)
	{
		if(m>=a[c].cha)
		{
			ans++;
			m-=a[c].cha;
		}
		c++;
		if(c>=n)
		{
			break;
		}
		//cout<<c<<' ';
	}
	int sum=0;
	for(int j=0;j<n-1;j++)
	{
		if(a[j].i==a[j+1].i)
	    {
	    	if(sum==0)
	    	{
	    		sum++;
			}
			sum++;
		}
	}
	//cout<<sum<<endl;
	//cout<<endl;
	cout<<max(sum,ans)<<endl;
	return 0;
} 

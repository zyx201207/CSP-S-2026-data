#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500050],dis[500050];
pair<long long,long long>sj[500050];
long long cnt=0;
long long solu30()
{
	long long ans=1;
	long long i=1;
	while(m-i>0)
	{
		m-=i;
		ans++;
		i++;
	}
	return ans;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	long long flag1=0,flag2=0;
	for(long long i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]!=i+1)
		{
			flag1=1;
		}
	}
	if(flag1==0)
	{
		cout<<solu30();
		return 0;
	}
	sort(a,a+n);
	long long x=a[0];
	sj[cnt]={0,0};
	for(long long i=1;i<n;i++)
	{
		dis[i-1]=a[i]-x;
		if(i>1)
		{
			if(dis[i-1]!=dis[i-2])
			{
				flag2=1;
			}
		}
		x=a[i];
		if(dis[i-1]!=0)
		{
			sj[++cnt]={i,i};
		}
		else
		{
			sj[cnt].second=i;
		}
	}
	if(flag2==0)
	{
		cout<<solu30();
		return 0;
	}
	long long ans=INT_MIN;
	for(long long i=0;i<=cnt;i++)
	{
		long long k=m;
		long long ansk=0;
		long long l=sj[i].first-1,r=sj[i].second;
		while(k>0)
		{
			ansk++;
			if(dis[l]<dis[r])
			{
				k-=dis[l];
				l--;
			}
			else if(dis[l]>dis[r])
			{
				k-=dis[r];
				r++;
			}
			else
			{
				k-=dis[r];
				long long q=l,w=r;
				while(dis[--q]==dis[++w])
				if(dis[q]>dis[w])
				{
					r++;
				}
				else
				{
					l--;
				}
			}
		}
		ans=max(ans,ansk);
	}
	cout<<ans-500048;
	return 0;
}

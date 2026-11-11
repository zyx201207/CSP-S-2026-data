#include <bits/stdc++.h>
using namespace std;
long long n,a[500005],b[500005],m,maxn,ans,num,l,sum;
map <long long,long long> mapp;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		mapp[a[i]]++;                      
	}
	sort(a+1,a+n+1);
	long long f=a[(n+1)/2];
	long long m_1=m;
	long long cnt=0;
	long long idx,fx=(n+1)/2;
	for(long long i=fx;i>=1 && m_1;i--)
	{
		if(m_1>=f-a[i] && f-a[i]>=0)
		{
			m_1-=(f-a[i]);
			a[i]=f;
			idx=i;
		}
	}
	int p=f;
	for(int i=1;i<=n;i++)
		b[i]=a[i];
	while(1)
	{
		for(long long i=fx;i>=idx && m_1;i--)
		{
			b[i]+=1;
			m_1--;
		}
		if(b[fx]==b[fx+1])
		{
			fx++;
			p=b[fx];
		}
		if(m_1==0)
			break;
	}
	for(long long i=1;i<=n;i++)
		if(a[i]==f)
			cnt++;
	for(long long i=1;i<=n;i++)
		if(b[i]==p)
			sum++;
	cout<<max(cnt,sum);
	/*
	ans=max(cnt,sum);
	num=0,l=0;
	for(int i=1;i<=n;i++)
	{
		if(mapp[a[i]]>=l)
		{
			l=max(l,mapp[a[i]]);
			num=max(num,a[i]);
		}
	}
	f=num;
	m_1=m;
	cnt=0,sum=0;
	fx=(n+1)/2;
	for(long long i=fx;i>=1 && m_1;i--)
	{
		if(m_1>=f-a[i] && f-a[i]>=0)
		{
			m_1-=(f-a[i]);
			a[i]=f;
			idx=i;
		}
	}
	p=f;
	for(int i=1;i<=n;i++)
		b[i]=a[i];
	while(1)
	{
		for(long long i=fx;i>=idx && m_1;i--)
		{
			b[i]+=1;
			m_1--;
		}
		if(b[fx]==b[fx+1])
		{
			fx++;
			p=b[fx];
		}
		if(m_1==0)
			break;
	}
	for(long long i=1;i<=n;i++)
		if(a[i]==f)
			cnt++;
	ans=max(ans,cnt);
	for(long long i=1;i<=n;i++)
		if(b[i]==p)
			sum++;
	ans=max(ans,sum);
	cout<<ans;
	* */
	return 0;
}

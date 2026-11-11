#include<bits/stdc++.h>
using namespace std;
long long n,m;
const int MAXN=5e5+1000;
long long a[MAXN];
long long sub[MAXN];
long long ans=-1;
void workA()
{
	long long t=0,cnt=0;
	while(t<=m)
	{
		cnt++;
		t+=cnt;
	}
	cnt--;
	if(cnt>n)cnt=n;
	cout<<cnt;
}
void workB()
{
	long long cha=sub[n];
	if(cha<0)cha=-cha;
	long long t=0,cnt=0;
	while(t<=m)
	{
		cnt++;
		t+=cha*cnt;
	}
	cnt--;
	if(cnt>n)cnt=n;
	cout<<cnt;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	bool pianfenB=true;
	bool pianfenA=true;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		sub[i]=a[i]-a[i-1];
		if(i>=2&&sub[i-1]!=sub[i])
		{			
			pianfenB=false;
		}
		if(a[i]!=i)
		{
			
			pianfenA=false;
		}
	}
	if(pianfenA)
	{
		workA();
		return 0;
	}
	else if(pianfenB==true)
	{
		workB();
		return 0;
	}


	for(long long i=1;i<=n;i++) //iµ½j 
	{
		for(long long j=i;j<=n;j++)
		{
			long long maxx=-0x3f3f3f3f;
			for(long long k=i;k<=j;k++)
			{
				maxx=max(maxx,a[k]);
			}
			long long cnt=0,use=0;
			for(long long k=i;k<=j;k++)
			{
				use+=maxx-a[k];
				cnt++;
				if(use>m+1)
				{
					cnt--;
					break;
				}
				
			}
			if(ans<cnt)
			{
				ans=cnt;
			}
			
		}
	}
	cout<<ans;
	return 0;
}

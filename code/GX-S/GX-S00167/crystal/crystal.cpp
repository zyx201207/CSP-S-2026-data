#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n,t[N],p[N];
ll a[N],s=0,m;
bool check(int x)
{
	ll y=m;//sheng yu de
	ll s1=0;//zhe ge de zui da zong shu
	for(int i=x;i>=1;i--)
	{
		if(y<0)
			break;
		if(y>=a[x]-a[i])
		{
			s1++;
			y-=(a[x]-a[i]);
		}
	}
	if(t[x]!=1)
	{
		int z=x-p[x];//yu chu shi wei zhi de ju li
		s1+=t[x]-z-1;
	}
	if(s<=s1)
	{
		s=s1;
		return 1;
	}
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	bool f=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=a[i-1]&&i!=1)
			f=1;
	}
	if(f==0)//dou xiang deng
	{
		cout<<n;
		return 0;
	}
	f=0;
	sort(a+1,a+n+1);
	for(int i=2;i<n;i++)
	{
		if(a[i]-a[i-1]!=a[i+1]-a[i])
			f=1;
	}
	if(f==0)//deng cha shu lie
	{
		ll f1[N];
		memset(f1,0,sizeof(f1));
		for(int i=1;i<=n;i++)
			f1[i]=f1[i-1]+i;
		ll g=a[2]-a[1];
		for(int i=2;i<=n;i++)
			if(f1[i-1]*g>m)
			{
				cout<<i-1;
				return 0;
			}
		return 0;
	}
	if(n<=5000)//n*n bao li
	{
		ll s=0;
		for(int i=1;i<=n;i++)
		{
			ll y=m,s1=0;
			for(int j=i;j>=1;j--)
			{
				if(y<0)
					break;
				if(a[i]-a[j]>y)
					break;
				else
				{
					y-=(a[i]-a[j]);
					s1++;
				}
			}
			s=max(s1,s);
		}
		cout<<s;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=a[i-1])
			p[i]=i;
		else
			p[i]=p[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=a[i-1])
			t[i]=1;
		else
			t[i]=t[i-1]+1;
	}
	for(int i=n-1;i>=1;i--)
	{
		//cout<<1<<endl;
		if(a[i]==a[i+1])
		{
			for(int j=i;j>=1;j--)
			{
				if(a[j]==a[i+1])
					t[j]=t[i+1];
				else
				{
					i=j+1;
					break;
				}
			}
		}
	}
	//for(int i=1;i<=n;i++)
		//cout<<t[i]<<' '<<p[i]<<endl;
	int l=1,r=n;
	while(l<r)//mao si you dian cuo de er fen
	{
		int mid=(l+r)/2;
		if(check(mid)==1)
			l=mid+1;
		else
			r=mid;
	}
	for(int i=2;i<=10;i++)
	{
		l=n*i/10,r=n;
		while(l<r)//mao si you dian cuo de er fen
		{
			int mid=(l+r)/2;
			if(check(mid)==1)
				l=mid+1;
			else
				r=mid;
		}
	}
	for(int i=2;i<=10;i++)
	{
		l=1,r=n/i;
		while(l<r)//mao si you dian cuo de er fen
		{
			int mid=(l+r)/2;
			if(check(mid)==1)
				l=mid+1;
			else
				r=mid;
		}
	}
	cout<<s;
	return 0;
}

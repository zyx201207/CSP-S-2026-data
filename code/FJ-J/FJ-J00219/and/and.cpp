#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[200005],twosum[105],ansi,sum;
bool f[200005];
struct Node{
	string s;
	ll id;
}s[200005];
struct y{
	string s;
	ll val;
}ans[200005];
bool cmp(Node a,Node b)
{
	ll i=a.s.size()-1;
	while(i>=0&&a.s[i]==b.s[i])
	{
		i--;
	}
	return a.s[i]>b.s[i];
}
string two(ll x,ll op)
{
	string k="";
	while(x)
	{
		char c=x&1;
		c+='0';
		x>>=1;
		k=k+c;
	}
    while(k.size()<op)
    {
		k=k+'0';
	}
	return k;
}
int main()
{
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	string q=two(a[n],0);
	ll mk=q.size();
	s[n].s=q,s[n].id=n;
	for(int i=1;i<n;i++)
	{
		s[i].s=two(a[i],mk);
		s[i].id=i;
	}
	sort(s+1,s+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<s[i].s.size();j++)
		{
			if(s[i].s[j]=='1')
			{
				twosum[j+1]++;
			}
		}
	}
	ll ms=mk;
	while(ms>0&&twosum[ms]<m)
	{
		ms--;
	}
	if(ms==0)
	{
		cout<<0;
		return 0;
	}
	sum+=1<<(ms-1);
	for(int i=1;i<=n;i++)
	{
		if(s[i].s[ms-1]=='1')
		{
			ans[++ansi].val=a[s[i].id];
			ans[ansi].s=s[i].s;
		}
		else
		{
			for(int j=0;j<s[i].s.size();j++)
			{
				if(s[i].s[j]=='1')
				{
					twosum[j+1]--;
				}
			}
		}
	}
	ll op=ansi;
	while(ms>0&&op>0)
	{
		ms--;
		if(twosum[ms]>=m)
		{
			for(int i=1;i<=ansi;i++)
			{
				if(!f[i]&&ans[i].s[ms-1]=='0')
				{
					f[i]=1;
					op--;
					for(int j=0;j<ans[i].s.size();j++)
					{
						if(ans[i].s[j]=='1')
						{
							twosum[j+1]--;
						}
					}
				}
			}
			sum+=1<<(ms-1);
		}
	}
	cout<<sum;
	return 0;
}

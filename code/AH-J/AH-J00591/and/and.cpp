#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+5,P=(1<<30);
int n,m;
int a[N];
string b[N];
int f[35],p[35],t[35];
bool ff[N];
vector<int>r;
void er(int x)
{
	for(int i=x;i<r.size()-1;i++)
	{
		r[i]=r[i+1];
	}
	r.pop_back();
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
		cin>>a[i];
		long long t=P,ai=a[i],h=0;
		while(t)
		{
			if(ai>=t)
			{
				ai-=t;
				b[i]+='1';
				f[h]++;
			}
			else
			{
				b[i]+='0';
			}
			t/=2;
			h++;
		}
	}
	int pt=-1;
	for(int i=0;i<31;i++)
	{
		if(m<1)
		{
			break;
		}
		if(f[i]<2)
		{
			continue;
		}
		if(m<f[i]-p[i])
		{
			pt=i;
			for(int j=1;j<=n;j++)
	    	{
		    	if(b[j][i]=='1'&&ff[j]==0)
		    	{
					r.push_back(j);
					for(int k=pt;k<31;k++)
					{
						t[k]+=(b[j][k]=='1'?1:0);
					}
				}
			}
			break;
		}
		m-=(f[i]-p[i]);
		for(int j=1;j<=n;j++)
		{
			if(b[j][i]=='1'&&ff[j]==0)
			{
				ff[j]=1;
				for(int k=0;k<31;k++)
				{
					p[k]+=(b[j][k]=='1');
				}
			}
		}
	}
	if(m>=1)
	{
		for(int i=pt;i<31;i++)
		{
			if(p[i]+t[i]<2)
			{
				continue;
			}
			int st=0;
			for(auto j:r)
			{
				if(b[j][i]=='1')
				{
					st++;
				}
			}
			if(st==1)
			{
				for(auto j:r)
		    	{
			    	if(b[j][i]=='1')
		    		{
		    			ff[j]=1;
		    			break;
		    		}
		    	}
			}
			if(st>m)
			{
				for(int j=0;j<r.size();j++)
		    	{
			    	if(b[r[j]][i]=='0')
		    		{
						er(j);
		    		}
		    	}
			}
			else if(st!=0)
			{
				for(int j=0;j<r.size();j++)
		    	{
			    	if(b[r[j]][i]=='1')
		    		{
						ff[r[j]]=1;
						m--;
						er(j);
		    		}
		    	}
			}
		}
		for(int i=0;i<m;i++)
		{
			ff[r[i]]=1;
		}
	}
	long long s=(P<<1)-1;
	for(int i=1;i<=n;i++)
	{
		s&=(ff[i]?a[i]:(P<<1)-1);
	}
	cout<<s;
}

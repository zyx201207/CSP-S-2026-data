#include<bits/stdc++.h>
using namespace std;
long long a[200100],n,m,k[40],sum=1,c,p[200100],maxx,f,r,e,q=-1,g,d=-1;
string b[200100];
bool t[200100];
map<int ,bool> w;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	k[0]=1;
	while(sum<=30)
	{
		k[sum]=k[sum-1]*2;
		sum++;
	}
	for(int i=1;i<=n;i++)
	{
		r++;
		cin>>e;
		if(w[e]==0)a[r]=e;
		w[e]=1;
		q=max(q,a[r]);
		if(g==0)
		{
			g=a[r];
		}
		else g&=a[r];
	}
	if(m==n)
	{
		cout<<g;
		return 0;
	}
	g=0;
	if(m==n-1)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i!=j)
				{
					if(g==0)
		{
			g=a[r];
		}
				}
				d=max(d,g);
			}
		}
		cout<<d;
		return 0;
	}
	if(m==1)
	{
		cout<<q;
		return 0;
	}
	n=r;
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		c=a[i];
		while(c>1)
		{
			if(c%2)b[i]+='1';
			else b[i]+='0';
			c/=2;
		}
		if(c%2)b[i]+='1';
		c/=2;
	}
	maxx=b[n-m+1].size();
	for(int i=1;i<=n;i++)
	{
		if(b[i].size()<maxx)
		{
			b[i]="";
		}
		else{
			maxx=i;
			break;
		}
	}
	c=b[maxx].size()-2;
	while(c>-1)
	{
		f=0;
		for(int i=maxx;i<=n;i++)
		{
			if(b[i].size()!=0)
			{
				if(b[i][c]=='1')
				{
					p[c]++;
				}
				f++;
			}
		}
		if(f==m)
		{
			for(int i=maxx;i<=n;i++)
			{
				if(b[i].size()!=0)
				{
					t[i]=1;
				}
			}
			break;
		}
		if(p[c]>=m)
		{
			for(int i=maxx;i<=n;i++)
			{
				if(b[i][c]=='0')
				{
					b[c]="";
				}
			}
		}
		c--;
	}
	for(int i=maxx;i<=n;i++)
	{
		if(b[i].size()!=0)
		{
			t[i]=1;
		}
	}
	for(int i=maxx;i<=n;i++)
	{
		if(t[i])
		{
			
			if(!sum)sum=a[i];
			else sum&=a[i];
		}
	}
	cout<<sum;
}

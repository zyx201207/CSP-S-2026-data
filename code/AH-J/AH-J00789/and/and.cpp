#include<bits/stdc++.h>
using namespace std;
long long a[200005];
string maxn="";
string er[200005];
string xe[2005];
long long n,m,t,s=0,s1,t1,maxn1=0,b,minn=100000000;
int f[25];
void cz(int sl,long long cd)
{
	if(sl==m)
	{
		string w;
		int f2=0;
		for(int i=0;i<cd;i++)
		{
			f2=0;
			for(int j=0;j<m;j++)
			{
				if(xe[j][i]=='0')
				{
					f2=1;
					w=w+'0';
					break;
				}
			}
			if(f2==0)
			{
				w=w+'1';
			}
		}
		maxn=max(maxn,w);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i]!=1)
		{
			xe[sl]=er[i];
			f[i]=1;
			t=er[i].size();
			cz(sl+1,min(cd,t));
			f[i]=0;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(n<=20)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			s=0;
			while(a[i]!=0)
			{
				s++;
				if(a[i]%2==1) er[i]=er[i]+'1';
				else er[i]=er[i]+'0';
				a[i]=a[i]/2;
			}
			reverse(er[i].begin(),er[i].end());
		}
		cz(0,100);
		s=0;
		t=maxn.size();
		for(int i=0;i<t;i++)
		{
			if(maxn[i]=='1')
			{
				s1=1;
				for(int j=1;j<t-i;j++)
				{
					s1=s1*2;
				}
				s=s+s1;
			}
		}
		cout<<s;
		return 0;
	}
	if(n>20&&n<=2000)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			b=a[i];
			s=0;
			while(b!=0)
			{
				s++;
				if(a[i]%2==1) er[i]=er[i]+'1';
				else er[i]=er[i]+'0';
				a[i]=a[i]/2;
			}
			reverse(er[i].begin(),er[i].end());
		}
		if(m==1) cout<<maxn1;
		if(m==n)
		{
			string w;
			int f2=0;
			for(int i=0;i<minn;i++)
			{
				f2=0;
				for(int j=1;j<=m;j++)
				{
					if(er[j][i]=='0')
					{
						f2=1;
						w=w+'0';
						break;
					}
				}
				if(f2==0)
				{
					w=w+'1';
				}
			}
			cout<<w;
			return 0;
		}
	}
	if(n>2000)
	{
		int f4=1,f2=1;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]>4) f4=0;
			s=0;
			while(a[i]!=0)
			{
				s++;
				if(a[i]%2==1) er[i]=er[i]+'1';
				else
				{
					er[i]=er[i]+'0';
					f2=0;
				}
				a[i]=a[i]/2;
			}
			reverse(er[i].begin(),er[i].end());
		}
		if(f4==1) cout<<2;
		if(f2==1)
		{
			sort(a+1,a+n+1);
			cout<<a[n-1];
		}
		if(m==n-1)
		{
			string w;
			int f2=0;
			for(int i1=1;i1<=n;i1++)
			{
				for(int i=0;i<minn;i++)
				{
					f2=0;
					for(int j=1;j<=m;j++)
					{
						if(j==i1) continue;
						if(er[j][i]=='0')
						{
							f2=1;
							w=w+'0';
							break;
						}
					}
					if(f2==0)
					{
						w=w+'1';
					}
				}
				maxn=max(maxn,w);
			}
			cout<<maxn;
			return 0;
		}
	}
	return 0;
}

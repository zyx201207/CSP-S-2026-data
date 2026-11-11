#include<bits/stdc++.h>
using namespace std;
long long a[200010],c[200010];
long long ans;
char b[200010];
char l,r;
inline long long read()
{
	long long x=0;int f=1;
	char c=getchar();
	while(c>'9'||c<'0')
	{
		if(c=='-')
		{
			f=-1;
		}
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		c[i]=c[i-1]+1;
		cin>>b[i];
	}
	int i=1,j=n;
	while(c[i]<c[j])
	{
		if(b[i]!=b[j])
		{
			if(a[i]>a[j])
			{
				ans+=a[j];
				a[i]-=a[j];
				i--;
			}
			else if(a[i]<a[j])
			{
				ans+=a[i];
				a[j]-=a[i];
				j++;
			}
			else
			{
				ans+=a[j];
			}
		}
		else
		{
			if(a[i]>a[j])
			{
				a[i]-=a[j];
				i--;
			}
			else if(a[i]<a[j])
			{
				a[j]-=a[i];
				j++;
			}
		}
		i++;j--;
	}
	cout<<ans;
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
long long a[200010],c[200010];
long long ans;
char b[200010];
char nv;
inline long long read()
{
	long long x=0;int f=1;
	char c=getchar();
	while(c>'9'||c<'0')
	{
		if(c=='-')
		{
			f=-1;
		}
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}
int main()
{
	freopen("string4.in","r",stdin);
//	freopen("string.out","w",stdout);
//qwq
	int n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		c[i]=c[i-1]+a[i];
		cin>>b[i];
	}
	
	long long ln=0,rn=0;
	for(int i=1,j=n;ln<=c[n]/2;i++,j--)
	{
		if(ln!=rn)
		{
			if(ln>rn)
			{
				if(b[j]==nv)
				{
					if(ln<(rn+a[j]))
					{
						nv=b[j];
					}
					rn+=a[j];
				}
				else if((ln-rn)>a[j])
				{
					ans+=a[j];
					rn+=a[j];
					i--;
				}
				else if((ln-rn)<a[j])
				{
					ans+=(ln-rn);
					rn+=a[j];					
					nv=b[j];
					j++;
				}
				else
				{
					ans+=a[j];
					rn=ln;
				}
			}
			else
			{
				if(b[i]==nv)
				{
					if(rn<(ln+a[i]))
					{
						nv=b[i];
					}
					ln+=a[i];
					
				}
				else if((rn-ln)>a[i])
				{
					ans+=a[i];
					ln+=a[i];
					j++;
				}
				else if((rn-ln)<a[i])
				{
					ans+=(rn-ln);
					ln+=a[i];					
					nv=b[i];
					i--;
				}
				else
				{
					ans+=a[i];
					ln=rn;
				}
			}
		}
		else
		{
			if(b[i]!=b[j])
			{
				if(a[i]>a[j])
				{
					ans+=a[j];
					nv=b[i];
					ln+=a[i];
					rn+=a[j];
					i--;
				}
				else if(a[i]<a[j])
				{
					ans+=a[i];
					nv=b[j];
					ln+=a[i];
					rn+=a[j];
					j++;
				}
				else
				{
					ln+=a[i];
					rn+=a[j];
				}
			}
		}
	}
	cout<<ans;
}


#include<bits/stdc++.h>
using namespace std;
long long a[200010],c[200010];
long long ans;
char b[200010];
char l,r;
inline long long read()
{
	long long x=0;int f=1;
	char c=getchar();
	while(c>'9'||c<'0')
	{
		if(c=='-')
		{
			f=-1;
		}
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}
int main()
{
	freopen("string4.in","r",stdin);
//	freopen("string.out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		c[i]=c[i-1]+1;
		cin>>b[i];
	}
	int i=1,j=n;
	while(c[i]<c[j])
	{
		if(b[i]!=b[j])
		{
			if(a[i]>a[j])
			{
				ans+=a[j];
				a[i]-=a[j];
				i--;
			}
			else if(a[i]<a[j])
			{
				ans+=a[i];
				a[i]-=a[j];
				j++;
			}
			else
			{
				ans+=a[j];
			}
		}
		else
		{
			if(a[i]>a[j])
			{
				a[i]-=a[j];
			}
			else if(a[i]<a[j])
			{
				a[j]-=a[i];
			}
		}
		i++;j--;
	}
	cout<<ans;
}
*/

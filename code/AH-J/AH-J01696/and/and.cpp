#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int ans;
	string s;
	int len;
}a[200100];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		a[i].ans=x;
		int len1=1;
		while(x>0)
		{
			if(x%2==1)a[i].s[len1]='1';
			else a[i].s[len1]='0';
			x/=2;
			len1++;
		}
		a[i].len=len1-1;
	}
	int max=0;
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i].ans>max)max=a[i].ans;
		}
		cout<<max;
		return 0;
	}
	if(m==n)
	{
		string ss=a[1].s;
		int lenss=a[1].len;
		for(int i=2;i<=m;i++)
		{
			string sss;
			int maxmax;
			if(lenss>a[i].len)maxmax=lenss;
			else maxmax=a[i].len;
			for(int j=1;j<=maxmax;j++)
			{
				if(ss[j]==a[i].s[j])sss[j]='1';
				else sss[j]='0';
			}
			a[i].len=maxmax;
			for(int j=1;j<=lenss;j++)
			{
				ss[j]=sss[j];
			}
		}
		int tt=0;
		for(int i=1;i<=lenss;i++)
		{
			int ttt=ss[i]-'0'+0;
			int tttt=1;
			for(int j=1;j<i;j++)
			{
				tttt*=2;
			}
			tt+=ttt*tttt;
		}
		cout<<tt<<endl;
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<n;i++)
		{
			string sss;
			int maxmax;
			if(a[i].len>a[i+1].len)maxmax=a[i].len;
			else maxmax=a[i+1].len;
				for(int j=1;j<=maxmax;j++)
				{
					if(a[i].s[j]==a[i+1].s[j])sss[j]='1';
					else sss[j]='0';
				}
				bool boo=true;
				for(int j=1;j<=maxmax;j++)
				{
					if(sss[j]!='1')boo=false;
				}
				int tt=0;
				for(int j=1;j<=maxmax;j++)
				{	
					int ttt=sss[maxmax+1-j]-'0'+0;
					int tttt=1;
					for(int k=1;k<j;k++)
					{
						tttt*=2;
					}
					tt+=ttt*tttt;
				}
				if(boo)tt=a[i].ans;
				if(tt>max)max=tt;	 
		}
		cout<<max<<endl;
		return 0;
	}
	return 0;
}

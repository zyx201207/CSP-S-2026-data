#include<bits/stdc++.h>
using namespace std;
#define int long long
long long n=0,a[1145140],b[1145140],v[35][1145140],vis[1145140],p=0,cnt=(1<<31)-1;
string s[200005];
int cmp(int x,int y)
{
	return x>y;
}
string boxx(int x)
{
	string s1;
	int xx=31;
	while(xx--)
	{
		char c=x%2+'0';
		s1=s1+c;
		x=x/2;
	}
	return s1;
}
int boxxx(int x)
{
	int xx=0,num=1;
	for(int i=0;i<=31;i++)
	{
		xx=xx+(s[x][i]-'0')*num;
		num=num*2;
	}
	return xx;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>p;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		s[i]=boxx(a[i]);
		vis[i]=1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=30;j>=0;j--)
		{
			if(s[i][j]=='1')
			{
				v[j][i]=1;
			}
			b[j]=b[j]+(s[i][j]=='1');
		}
	}
	for(int i=30;i>=0;i--)
	{
		if(b[i]>=p)
		{
			for(int j=1;j<=n;j++)
			{
				if(v[i][j]==0)
				{
					vis[j]=0;
					for(int k=0;k<=30;k++)
					{
						if(v[k][j])
						{
							b[k]--;
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==1&&p>0)
		{
			cnt=(cnt&boxxx(i));
			p--;
		}
	}
	cout<<cnt;
}

#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000005];
bool check(int u,int v)
{
	int now=u;
	string s1="",s2="";
	s1=u+'0';
	while(now<v)
	{
		for(int i = v;i>u;i--)
		{
			if(a[i]<=a[now]+d)
			{
				now=i;
				s1+=i+'0';
				break;
			}
		}
	}
	now=v;
	s2=v+'0';
	while(now>u)
	{
		for(int i = u;i<=v;i++)
		{
			if(a[i]>=a[now]-d)
			{
				now=i;
				s2=char(i+'0')+s2;
				break;
			}
		}
	}
	if(s1!=s2)
	{
		cout<<s1<<' '<<s2<<endl;
	}
	return s1!=s2;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i = 0;i<n;i++)
		{
			cin>>a[i];
		}
		int ans=0;
		for(int i = 0;i<n;i++)
		{
			for(int j = i+2;j<n;j++)
			{
				if(check(i,j))
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
} 

#include<bits/stdc++.h>
using namespace std;
int n,cnt=1;
int a[200005];
char ch[200005];
string s[200005];
string hw[200005];
bool f[200005];
string str;
void dfs(int len,string pos)
{
	if(len>=str.size())
	{
		s[cnt]=pos;
		cnt++;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(f[i]==0)
			{
				dfs(len+1,pos+ch[i]);
				f[i]=0;
			}
		}
	}
}
int huiwen(string s)
{
	bool fl=1;
	int l=0,r=s.size();
	while(l<r)
	{
		if(s[l]!=s[r])
		{
			fl=0;
		}
	}
	return fl;
}
int db(string s1)
{
	int dbf=0;
	for(int i=0;i<str.size();i++)
	{
		if(s1[i]!=str[i])
		{
			dbf++;
		}
	}
	return dbf;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	if(n<=2)
	{
		if(n==1)
		{
			cout<<0;
			return 0;
		}
		else
		{
			int a1,a2;
			char c1,c2;
			cin>>a1>>c1>>a2>>c2;
			if(c1!=c2)
			{
				cout<<min(a1,a2);
			}
			else
			{
				cout<<0;
			}
			return 0;
		}
	}
	else 
	{
		int flag=1;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>ch[i];
			if(a[i]!=1)
			{
				flag=0;
			}
			for(int j=1;j<=a[i];j++)
			{
				str=str+ch[i];
			}
		}
		if(flag==1)
		{
			if(n%2==0)
			{
				cout<<n/2;
			}
			else
			{
				cout<<(n-1)/2;
			}
		}
		else
		{
			dfs(0,"");
			int mi=INT_MAX;
			for(int i=1;i<=cnt;i++)
			{
				if(huiwen(s[i])==1)
				{
					cout<<s[i]<<endl;
					mi=min(mi,db(s[i]));
				}
			}
			cout<<mi;
		}
	}
	return 0;
}

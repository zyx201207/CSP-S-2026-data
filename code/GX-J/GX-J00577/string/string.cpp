#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
string s;
int n,ans;
bool huiwen(string ss)
{
		int len=ss.size();
		for(int i=0,j=len-1;i!=j;i++,j--)
			if(ss[i]!=ss[j])
				return 0;
		return 1;
}
int main()
{
		freopen("string.in","r",stdin);
		freopen("string.out","w",stdout);
		cin>>n;
		while(n--)
		{
				int m;
				char c;
				cin>>m>>c;
				for(int i=1;i<=m;i++)
					s+=c;
		}
		if(huiwen(s)==1)
		{
				cout<<0;
				return 0;
		}
		int len=s.size();
		for(int i=0,j=len-1;i!=j;i++,j--)
		{
			if(s[i]!=s[j])
				ans++;
		}
		cout<<ans;
		return 0;
}



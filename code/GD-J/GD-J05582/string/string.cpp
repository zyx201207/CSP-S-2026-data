#include<bits/stdc++.h>
using namespace std;
struct
{
	int a;
	string c;
}b[1000005];
string s[1000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		cin>>b[i].a>>b[i].c;
		for(int j=1;j<=b[i].a;j++)
		{
			s[j]=b[j].c;
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		cnt+=b[i].a;
	}
	if(cnt%2==0)
	{
		int mul=0;
		int l=1,r=cnt;
		for(int i=1;i<=cnt;i++)
		{
			if(s[l]==s[r])
			{
				l++,r--;
			}
			else
			{
				mul++,l++,r--;
			}
			if(l==r)
			{
				cout<<mul;
				return 0;
			}
		}
		
	}
	else
	{
		int mul=0;
		int l=1,r=cnt;
		for(int i=1;i<=cnt;i++)
		{
			if(s[l]==s[r])
			{
				l++,r--;
			}
			else
			{
				mul++,l++,r--;
			}
			if(r-l==2)
			{
				cout<<mul;
				return 0;
			}
		}
	}
	
}

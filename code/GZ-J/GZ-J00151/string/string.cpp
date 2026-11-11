//GZ-J00151 安顺市实验学校 罗子骏
#include <bits/stdc++.h>
using namespace std; 
int n,l,cnt;
string s;
bool f=1;
char m;
int main()
{	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>l>>m;
		s+=m*l;
	}
	int c=s.size();
	for(int i=1;i<=c/2;i++)
	{
		if(s[i]!=s[c-i]) 
		{
			f=0;
			break;
		}
	}
	if(f)
	{
		cout<<'0';
		return 0;
	}
	else 
	{
		if(c%2==0)
		{
			for(int i=1;i<=c/2;i++)
			{
				if(s[i]!=s[i+(c/2)])
				{
					cnt++;
				}
			}
		}
		else 
		{
			cout<<'0';
			return 0;
		}
	}
	cout<<cnt;
	return 0;
} 

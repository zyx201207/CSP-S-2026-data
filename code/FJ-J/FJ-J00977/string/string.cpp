#include<bits/stdc++.h>
using namespace std;
long long int n,x,num,sum;
char c;
string s,s1;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(long long int i=0;i<n;i++)
	{
		cin>>x>>c;
		for(long long int j=1;j<=x;j++)
		{
			s=s+c;
		}
		num+=x;
	}
	for(long long int i=0;i<=num-1;i++)
	{
		s1[i]=s[num-1-i];
	}
	if(s1==s)
	{
		cout<<0;
	}
	else
	{
		for(int i=0;i<=num-1;i++)
		{
			if(s1==s)
			{
				break;
			}
			if(s1[i]!=s[i])
			{
				s1[i]==s[i];
				s[num-1]==s[i];
				sum++;
				num--;
			}
		}
		cout<<sum;
	}
	return 0;
}


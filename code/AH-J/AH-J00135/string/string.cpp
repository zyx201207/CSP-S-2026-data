#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int cnt,n,x;
char ch;
int main()
{
	freopen("string.in","r",stdin);
	freopen("strin.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>ch;
		for(int j=1;j<=x;j++)
			s1+=ch;
	}
	s2=s1;
	reverse(s2.begin(),s2.end());
	if(s2==s1)
		cout<<"0";
	else
	{
		for(int i=0,j=s2.size();i<j;i++)
		{
			if(s2[i]!=s1[i])
			{
				s2[i]=s1[i];
				cnt++;
				string s4=s2;
				string s3=s2;
				reverse(s4.begin(),s4.end());
				if(s4==s3)
				{
					cout<<cnt;
					return 0;
				}
			}
		}
	}
}


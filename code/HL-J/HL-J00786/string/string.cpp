#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n; cin>>n;
	string s;
	for(int i=0;i<n;i++)
	{
		char a,b; cin>>a>>b;
		s+=a;
		s+=b;
	}
	string s2=s;
	int cnt=0;
	for(int i=0;i<=s2.size()-1;i++)
	{
		for(int j=s.size()-1;j>=0;j--)
		{
			if(s2[i]==s[j])
			{
				 cout<<"0";
				 return 0;
			}
			else 
			{
				if(s2[i]!=s[j]) s[j]=s2[i];
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;      
}
#include<bits/stdc++.h>
using namespace std;
int n;
string s,s2;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		char c;
		cin>>x>>c;
		for(int j=1;j<=x;j++)
		{
			s+=c;
		}
	}
	long long sum=0;
	s2=s;
	reverse(s2.begin(),s2.end());
	for(int i=0,j=s2.size()-1;i<s.size()&&j>=0;i++,j--)
	{
		if(s2[i]!=s[i]) 
		{
			s[j]=s[i];
			s2[i]=s2[j];	
			sum++;
		}
	}
	cout<<sum;
	return 0;
} 


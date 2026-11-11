#include<bits/stdc++.h>
using namespace std;
int n,len,ans;
string s,s1,s2,s3;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		char y;
		cin>>x;
		cin>>y;
		for(int j=1;j<=x;j++)
		{
			s+=y;
		}
	}
	len=s.length()/2;
	s1=s.substr(0,len);
	if(len*2!=s.length()) s2=s.substr(len+1,len);
	else s2=s.substr(len,len);
	s3=s2;
	for(int i=s2.length()-1,j=0;i>=0;i--,j++)
	{
		s3[i]=s2[j];
	}
	for(int i=0;i<min(s1.length(),s3.length());i++)
	{
		if(s1[i]!=s3[i]) ans++;
	}
	cout<<ans;
	return 0;
}

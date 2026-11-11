#include<bits/stdc++.h>
using namespace std;
int n,m,sum=0;
char a;
string s="";
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m>>a;
		for(int j=1;j<=m;j++)
		{
			s+=a;
		}
	}
	for(int i=0,j=s.size();i<=j;i++,j--)
	{
		if(s[i]!=s[j])
		{
			sum++;
		}
	}
	cout<<sum;
	return 0;
} 

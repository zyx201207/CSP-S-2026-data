#include<bits/stdc++.h>
using namespace std;

string s[99999999];
int main()
{
	freopen("string.in","r",stdin);
	//foropen("cs-1.out","w",stdout);
	freopen("string.out","w",stdout);
	int n,e1=0;
	//string c1,s1,c2,s2;
	cin>>n;	
	for(int i=0;i<=n;i++)
	{
		int w1;
		char w2;
		cin>>w1>>w2;
		for(int j=1;j<=w1;j++)
		{
			s[e1]=w2;
			e1++;
		}
	}
	
	for(int i=1;i<=e1;i++)
	{
		cout<<s[i];
	}
	
	
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int sum=0;
	string s1="";
	for(int i=1;i<=n;i++)
	{
		int a;
		string c;
		cin>>a>>c;
		for(int i=1;i<=a;i++)
		{
			s1+=c;
			
		}
		
	}
	for(int i=0;i<s1.size();i++)
	{
		if(s1[i]==s1[i+1])
		{
			cout<<0;
			return 0;
		}
		
				
	}
	cout<<n-1;
	
	return 0;
} 
//3
//2 a
//2 b
//1 c

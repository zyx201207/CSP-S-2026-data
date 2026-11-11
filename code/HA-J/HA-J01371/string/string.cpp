#include<bits/stdc++.h>
using namespace std;
	string a;
	char aa;
	int b,bb=0;
	int n; 
void sum(string x)
{
	if(x.size()%2==0)
	{
		for(int i=0;i<x.size()/2;i++)
		{
			if(x[i]!=x[x.size()-1-i])
				bb++;
		}
	}
	else
	{
		for(int i=0;i<(x.size()-1)/2;i++)
		{
			if(x[i]!=x[x.size()-1-i])
				bb++;
		}	
	}
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>b>>aa;
		for(int j=0;j<b;j++)
			a=a+aa;
	}
	sum(a);
	cout<<bb;
	fflush(stdout);
	return 0;
}

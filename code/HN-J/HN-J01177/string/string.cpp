#include<bits/stdc++.h>
using namespace std;
string S;
long long a;
long long b;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		long long x;
		char y;
		cin>>x>>y;
		for(int j=0;j<x;j++)
		{
			S[a]=y;
			a++;	
		}	
	}
	a--;
	for(int i=0;i<=a;i++)
	{
		int u=a-i;
			if(S[i]!=S[u])
			{
				b++;	
			}
	}
	cout<<b/2;
	return 0;
}

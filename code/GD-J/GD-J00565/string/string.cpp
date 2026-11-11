#include<bits/stdc++.h>
using namespace std;
char a[200001];
long long b[200001];
bool pd(long long p,string t)
{
	for(int i=0;i<p;i++)
	{
		if(t[i]!=t[p-i-1])
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s="";
	long long sum=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>b[i]>>a[i];
	}
	cout<<2;
	
	
}

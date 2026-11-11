#include <bits/stdc++.h>
using namespace std;
string f;
int main()
{
	freopen("string.in","r","stdin");
	freopen("string.out","w","stdout");
	long long n;
	cin>>n;
	long long cnt=0,sum=0;
	for(int i=0;i<n;i++)
	{
		long long  a;
		char b;
		cin>>a>>b;
		for(int j=0;j<a;j++)
		{
			cnt++;
			f[cnt]=b;
			
		}
	}
	for(int i=1;i<=cnt;i++)
	{
		if(f[i]!=f[cnt-i+1])
		{
			sum++;
		}
	}
	cout<<sum;
	
	
}


#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m;
	string a="",b;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m>>b;
		for(int j=1;j<=m;j++)
		{
			a+=b;
		}
	}
	long long sum=0,w=a.size();
	for(int i=0;i<w/2;i++)
	{
		if(a[i]!=a[w-i-1])
			sum++;
	}
	cout<<sum;
} 

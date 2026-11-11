#include<bits/stdc++.h>

using namespace std;
const int N=1e5*2+5;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long a[N];
	char c[N];
	string p;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>c[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<a[i];j++)
		{
			p+=c[i];
		}
	}
	long long cnt=0,len=p.size();
	for(int i=0;i<len/2;i++)
	{
		if(p[i]!=p[len-1-i])cnt++;
	}
	cout<<cnt;
	return 0;
}

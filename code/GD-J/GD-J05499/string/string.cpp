#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],len=0,f=0,t,sum=0;
char c;
map<int,char>s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c;
		for(int j=0;j<a[i];j++)
		{
			s[len++]=c;
		}
	}
	for(int i=0;i<len/2;i++)
	{
		if(s[i]!=s[len-i-1])
		{
			sum++;
		}
	}
	cout<<sum;
	return 0;
}

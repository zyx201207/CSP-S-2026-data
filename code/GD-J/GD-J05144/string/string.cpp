#include <bits/stdc++.h>
using namespace std;
int n,a;
char c;
string s;
long long f(long long l)
{
	long long sum=0;
	for(long long i=0;i<l/2;i++)
	{
		if(s[i]!=s[l-i-1])
			sum++;
	}
	return sum;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int j=1;j<=a;j++)
			s+=c;
	}
	long long l=s.size();
	long long ans=f(l);
	cout<<ans;
	return 0;
}

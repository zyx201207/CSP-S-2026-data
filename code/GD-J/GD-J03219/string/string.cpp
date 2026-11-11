#include <bits/stdc++.h>
using namespace std;
vector<char> s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long num=0,sum=0;
	while(n--)
	{
		long long x;
		cin>>x;
		char c;
		cin>>c;
		for(long long i=num;i<num+x;i++)
		{
			s.push_back(c);
		}
		num+=x;
	}
	if(num%2==0)
	{
		sum=num/2;
	}
	else
	{
		sum=num/2+1;
	}
	long long cnt=0;
	for(long long i=0;i<sum;i++)
	{
		if(s[i]!=s[s.size()-1-i])
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}

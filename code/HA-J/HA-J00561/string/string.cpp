#include<bits/stdc++.h>
using namespace std;

const int N=1e2+5;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin>>n;
	
	long long a,len=0;
	char c;
	string s;
	for(int i=1; i<=n; i++)
	{
		cin>>a>>c;
		len+=a;
		for(int i=1; i<=a; i++)
		{
			s+=c;
		}
	}
	
	int num=0;
	
	string s1=s;
	reverse(s1.begin(),s1.end());
	
	if(s==s1)
	{
		cout<<num;
		return 0;
	}
	else
	{
		num=len/2;
		if(len%2==0)
		{
			cout<<num;
		}
		else
		{
			num+=0.5;
			cout<<num;
		}
	}
	return 0;
}

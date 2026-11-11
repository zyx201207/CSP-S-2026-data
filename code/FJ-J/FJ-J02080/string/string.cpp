#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	string s;
	long long sum=0;
	long long n;
	cin>>n;
	long long loong=0;
	for(int i=1;i<=n;i++)
	{
		long long a;
		string f;
		cin>>a>>f;
		for(long long j=1;j<=a;j++)
			s+=f;
		loong+=a;
	}
	long long mild=loong/2;
	long long l;
	long long r;
	if(loong%2==1)
	{
		l=mild-1;
		r=mild+1; 
		
	}
	else 
	{
		l=mild-1;
		r=mild;
	}
	while(l>=0)
	{
		if(s[l]!=s[r])
			sum++;
		l--;
		r++;
	}
	cout<<sum;
	return 0;
} 












#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string a;
	long long cnt=0;
	long long N;
	cin>>N;
	long long ai;
	char ci;
	for(long long i=1;i<=N;i++)
	{
		cin>>ai>>ci;
		for(long long j=1;j<=ai;j++)
		{
			a += ci;
		}
	}
	long long p_st=0;
	long long p_ed=a.size()-1;
	long long len_a = a.size();
	
	for(long long i=1;i<=len_a/2;i++)
	{
		if(a[p_st] != a[p_ed])
		{
			cnt++;
		}
		p_st++;
		p_ed--;
	}
	
	cout<<cnt<<endl;
	
	
}

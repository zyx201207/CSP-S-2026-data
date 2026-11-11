#include<bits/stdc++.h>
using namespace std;
vector<long long>s;
vector<long long>b;
long long n,m;
long long maxi=0;
void f(long long a,long long b,long long end,long long c,long long sum)
{
	if(a>=end)
	{
		//b.push_back(c);
		//cout<"t";
		maxi=max(maxi,c&sum);
		return;
	}
	for(long long i=b;i<n;i++)
	{
		//for(long long j=0;j<a;j++)cout<<" ";
		//cout<<s[i]<<"\n";
		if(a==0)f(a+i,i+1,end,s[i],s[i]);
		else f(a+1,i+1,end,c&sum,s[i]);
	}
	return;
}
int main()
{
	ios::sync_with_stdio(nullptr);
	cin.tie(nullptr);
	cin>>n>>m;
	for(long long i=0;i<n;i++)
	{
		long long x;
		cin>>x;
		s.push_back(x);
	}
	f(0,0,m,0,0);
	cout<<maxi;
	return 0;
}
// 4 2 3 15 12 12
//5 3 31 3 1 15 7

#include<bits/stdc++.h>
using namespace std;

int a[20009];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long N,M;
	cin>>N>>M;
	for(long long i=1;i<=N;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+N+1);
	long long sum=a[N];
	for(long long j=N-1;j>N-M;j--)
	{
		sum = (sum & a[j]);
	}
	cout<<sum<<endl;
 } 

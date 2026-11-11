#include<bits/stdc++.h>
using namespace std;
int x[200005];
char y;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n; 
	string s;
	long long sum=0;
	for(int i=1;i<n;i++)
	{
		cin>>x[i]>>y;
		for(int j=sum;j<sum+x[i];j++)
		{
			s[j]=0;
			s[j]+=y;
		}
		sum+=x[i];
	}
	cin>>x[n-1]>>y;
	for(int j=sum;j<sum+x[n-1];j++)
	{
		s[j]=0;
		s[j]+=y;
	}
	sum+=x[n-1];
	int cnt=0;
	for(int i=0;i<sum/2;i++)
	{
		if(s[i]!= s[sum-i-1])
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}

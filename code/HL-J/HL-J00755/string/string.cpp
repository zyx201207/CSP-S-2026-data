#include <bits/stdc++.h>
using namespace std;	
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,a;
	int sum=0;
	int w=0;
	int cnt=0;
	char c;
	cin>>n;
	char S[100050];
	char X[100050];
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		sum+=a;
		for(int j=w;j<sum;j++)
		{
			S[j]=c;
		}
		w+=a;
	}
	for(long i=0;i<sum;i++)
	{
		for(long j=sum-1;j>=0;j--)
		{
			X[i]=S[j];
		}
	}
	for(long i=0;i<sum;i++)
	{
		if(X[i]!=S[i])
		{
			cnt++;
		}
	}
	cout<<cnt;

	
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5;
int a[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	string str;
	long long cnt=0;
	char ch;
	for(int i=1;i<=n;i++)
	{
		int num;

		cin>>num>>ch;
		cnt+=num;
		for(int j=1;j<=num;j++)
		{
			str+=ch;
		}
	}
	long long sum=cnt;
	for(int i=1;i<=cnt;i++)
	{
		if(ch!=str[i]) break;
		else sum--;
	}
	if(sum==0)
	{
		cout<<0;
		return 0;
	}
	if(cnt%2!=0)
	{
		int cntt=0,j=cnt/2;
		for(int i=cnt/2;i>=0;i--)
		{
			if(str[j]!=str[i]) cntt++;
			j++;
		}
		cout<<cntt;
		return 0;
	}
	else
	{
		int cnttt=0,jj=cnt/2+1;
		for(int i=cnt/2;i>=0;i--)
		{
			if(str[jj]!=str[i]) cnttt++;
			jj++;
		}
		cout<<cnttt;
		return 0;
	}
	return 0;
} 
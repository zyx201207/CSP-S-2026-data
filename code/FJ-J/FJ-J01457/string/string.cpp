#include<bits/stdc++.h>
using namespace std;
string s="";
char x[1];
int a,b,n,num;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>num>>x;
		for(int j=1;j<=num;j++)
		{
			s+=x;
		}
	}
	int sum=0;
	int y=s.size();
	for(int i=0;i<y/2;i++)
	{
		if(s[i]!=s[y-i-1])
		{
			sum++;
		}
	}
	cout<<sum;
	return 0;
}

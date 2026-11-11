#include<bits/stdc++.h>
using namespace std;
char s[20000010];
int size;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		char ch;
		cin>>x>>ch;
		for(int j=1;j<=x;j++)size++,s[size]=ch;
	}
	int sum=0;
	for(int i=1;i<=size/2;i++)
	{
		if(s[i]!=s[size-i+1])sum++;
	}
	cout<<sum;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	long long a,ai=0;
	string c,str;
	long long cnt=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a>>c;
		ai+=a;
		for(int j=0;j<a;j++)
		{
			str+=c;
		}
	}
	for(int i=0;i<ai/2;i++)
	{
		if(str[i]!=str[ai-i])
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}

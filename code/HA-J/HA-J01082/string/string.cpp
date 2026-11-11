#include<bits/stdc++.h>
using namespace std;
string s;
long long n;
long long sum;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int m;
		char ss1;
		cin>>m;
		cin>>ss1;
		for(int i=1;i<=m;i++)
		{
			s+=ss1;
		}
	}
	long long l=s.size();
	for(int i=0;i<l/2;i++)
	{
		if(s[i]!=s[l-i-1])
		{
			sum++;
		}
	}
	cout<<sum;
	return 0;
}

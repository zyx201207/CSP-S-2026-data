#include <bits/stdc++.h>
using namespace std;
int main()
{
 	freopen("string.in","r",stdin);
 	freopen("string.out","w",stdout);
 	int n;
 	cin>>n;
 	long long a;
 	char c;
 	string s="";
 	for(int i=1;i<=n;i++)
 	{
 		cin>>a>>c;
 		for(long long j=1;j<=a;j++)
 		{
 			s+=c;
		}
	}
	long long num=0;
	long long snum=s.size();
	for(long long i=0;i<snum/2;i++)
	{
		if(s[i]!=s[snum-i-1])
		{
			num++;
		}
	}
	cout<<num;
 	return 0;
}


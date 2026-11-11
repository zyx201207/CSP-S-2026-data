#include<bits/stdc++.h>
using namespace std;
long long n,a;
string b;
string s1,s2;
long long sum;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		cin>>b;
		for(int j=1;j<=a;j++)
		{
			s2+=b;
		}
	}
	s1=s2;
	reverse(s2.begin(),s2.end());
	for(int i=0;i<s1.size();i++)
	{
		if(s1[i]!=s2[i])
		{
			sum++;
		}
		else{
			break;
		}
	}
	cout<<sum;
	return 0;
}

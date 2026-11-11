#include<bits/stdc++.h>
using namespace std;
long long n,t,sum;
char c;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n)
	{
		n--;
//		cout<<1;
		cin>>t>>c;
		for(int i=1;i<=t;i++)
		{
			s+=c;
		} 
	}
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!=s[s.size()-i-1])
		{
			sum++;
			s[i]=s[s.size()-i-1];
		}
	}
	cout<<sum;
	return 0;
}

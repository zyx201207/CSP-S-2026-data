#include<bits/stdc++.h>
using namespace std;
long long n;
string s="";
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	while(n--)
	{
		int a;
		string c;
		cin>>a>>c;
		while(a--)s+=c;
	}
	long long l=0,r=s.size()-1,sum=0;
	while(l<=r)
	{
		if(s[l]!=s[r])sum++;
		l++;
		r--;
	}
	cout<<sum;
	return 0;
}

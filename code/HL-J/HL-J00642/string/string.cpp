#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll n,cnt=0,sl,len;
char zf;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>sl;
		cin>>zf;
		for(int j=0;j<sl;j++)
		{
			s+=zf;
		}
	}
	len=s.size();
	for(int i=len/2+1;i<=len;i++)
	{
		if(s[i-1]!=s[len-i])
		{
			s[i-1]=s[len-i];
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}

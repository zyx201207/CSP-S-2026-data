#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N=2e5+10;
ull a[N],n,sum=0,cnt=0;
char s[N];
string s1,s2;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(ull i=0;i<n;i++)
	{
		cin>>a[i]>>s[i];
		sum+=a[i];
		for(int i=0;i<a[i];i++)
		{
			s1+=s[i];
		}
	}
	for(ull i=s1.size()-1;i>=0;i--)
	{
		s2+=s1[i];
	}
	if(s1==s2)
	{
		cout<<0;
		return 0;
	}
	for(ull i=0;i<sum;i++)
	{
		if(s1[i]!=s2[i])
		{
			cnt++;
		}
	}
	cout<<cnt/2;
	return 0; 
}

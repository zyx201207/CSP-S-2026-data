#include<bits/stdc++.h>
using namespace std;
long long n,bb,sum=0,mid,ans=0,ans1=0,cnt=1;
char ch;
string s,s1;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--)
	{
		cin>>bb>>ch;
		for(int i=cnt;i<=cnt+bb;i++)
		{
			s[i]=ch;
		}
		cnt+=bb;
	}
	for(int i=cnt;i>=1;i--)
	{
		s1[i]=s[++sum];
	}
	mid=cnt/2+1;
	for(int i=1;i<mid;i++)
	{
		if(s[i]!=s1[i]) ans++;
	}
	for(int i=mid+1;i<=sum;i++)
	{
		if(s[i]!=s1[i]) ans1++;
	}
	cout<<min(ans1,ans);
	return 0;
}

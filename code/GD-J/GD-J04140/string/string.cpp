#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n=0;
	string s;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		int a=0;char c;
		cin>>a>>c;
		for(int i=1;i<=a;++i)
		{
			s+=c;
		}
	}
	string sh="";
	for(long long i=s.size()-1;i>=0;i--)
	{
		sh+=s[i];
	}
	if(s==sh)
	{
		cout<<0;return 0;
	}
	
	long long mid=s.size()/2;
	long long cnt=0;
	for(long long i=s.size()-1,j=0;i>=mid;i--,j++)
	{
		if(s[i]!=s[j])
		{
			s[i]=s[j];
			cnt++;
		}
		bool flag=0;
		for(long long k=i-1,b=j+1;k>j;k--,b++)
		{
			if(s[k]!=s[b])
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			cout<<cnt;
			return 0;
		}
	}
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

3
2 a
2 b
1 c
*/

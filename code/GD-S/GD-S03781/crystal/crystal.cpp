#include<bits/stdc++.h>
using namespace std;
int n,m,sum=0,maxn=INT_MIN,a[500005],sum1[100005];
string s;
string qz0(int x)
{
	string s1=to_string(x);
	s1.reserve(s1.size());
	while(s1.size()<n)
	{
		s1+="0";
	}
	s1.reserve(s1.size());
	return s1;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		memset(sum1,0,sizeof(sum1));
		s=qz0(i);
		for(int j=0;j<=s.size()-1;j++)
		{
			a[j+1]+=(s[j]-'0');
		}
		for(int j=1;j<=n;j++)
		{
			sum1[a[j]]+=1;
			maxn=max(maxn,sum1[a[j]]);
		}
		for(int j=0;j<=s.size()-1;j++)
		{
			a[j+1]-=(s[j]-'0');
		}
	}
	cout<<maxn<<endl;
	return 0;
}

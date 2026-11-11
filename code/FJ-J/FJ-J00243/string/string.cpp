#include<bits/stdc++.h>
using namespace std;
string a;
char b;
int minn=0,n,m,l[30],len,r[30];
bool check(string p)
{
	for(int i=0;i<=len/2;i++)
	{
		if(p[i]!=p[len-i])
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m>>b;
		for(int j=1;j<=m;j++)
		{
			a+=b;
		}
	}
	len=a.size()-1;
	if(check(a))
	{
		cout<<0;
		return 0;
	}
	for(int i=0;i<=len/2;i++)
	{
		l[a[i]-'a'+1]++;
	}
	for(int i=len/2+1;i<=len;i++)
	{
		r[a[i]-'a'+1]++;
	}
	for(int i=1;i<=26;i++)
	{
		minn+=abs(l[i]-r[i]);
	}
	cout<<(minn+1)/2;
	return 0;
}

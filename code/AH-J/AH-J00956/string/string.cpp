#include<bits/stdc++.h>
using namespace std;
int back(string x)
{
	string y;
	for(int i=x.size()-1;i>=0;i--)
	{
		y+=x[i];
	}
	if(y==x) return 1;
	else return 0;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,k=0;
	int a[200005];
	char c[200005];
	string s;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++)
		{
			s+=c[i];
		}
	}
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	if(back(s)==1)
	{
		cout<<0;
		return 0;
	}
	int mid;
	if(s.size()%2==0) mid=s.size()/2-1;
	else mid=s.size()/2;
	for(int i=mid+1;i<s.size();i++)
	{
		if(s[i]!=s[s.size()-i-1]) k++;
	}
	cout<<k;
}

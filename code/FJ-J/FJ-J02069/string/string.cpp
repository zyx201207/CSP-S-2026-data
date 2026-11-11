#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
struct node
{
	int x;
	char c;
}a[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0;
	string s="";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].x>>a[i].c;
		for(int j=0;j<a[i].x;j++)
		{
			s+=a[i].c;
		}
	}
	n=s.size();
	for(int i=0;i<(n+1)/2;i++)
	{
		if(s[i]!=s[n-i-1])
		{
			s[n-i-1]=s[i];
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

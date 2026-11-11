#include<bits/stdc++.h>
using namespace std;
int n;
struct node
{
	long long x;
	string sa;
}a[200005];
long long k;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].sa;
		k+=a[i].x;
		for(int j=1;j<=a[i].x;j++)s=s+a[i].sa;
	}
	long long ans=0;
	for(long long i=0;i<k/2;i++)
	{
		if(s[i]!=s[k-i-1])s[k-i-1]=s[i],ans++;
	}
	cout<<ans;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long ss=0;
long long a[100000001];
void h2(string s)
{
	long long ans=s.size();
	for(long long i=0;i<=(ans-1)/2;i++)
	{
		if(s[i]!=s[ans-1-i]) ss++;
	}
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++)
	{
		string x;
		cin>>a[i]>>x;
		for(long long j=1;j<=a[i];j++) s+=x;
	}
	h2(s);
	cout<<ss;
	return 0; 
}

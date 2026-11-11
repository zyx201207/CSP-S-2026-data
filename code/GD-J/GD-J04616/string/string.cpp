#include<bits/stdc++.h>
using namespace std;
string s;
char a;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0); 
	long long n,x,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>a;
		for(int j=1;j<=x;j++)s+=a;
	}
	for(int i=0,j=s.size()-1;i<=j;i++,j--)
	{
		if(s[i]!=s[j])sum++;
	}
	cout<<sum;
	return 0;
}

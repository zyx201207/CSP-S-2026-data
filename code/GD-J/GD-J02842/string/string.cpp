#include <bits/stdc++.h>
using namespace std;
int a[100005],c[100005];
int main()
{
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	string s="";
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++)
	{
		s+=a[i]*c[i];
	}
	int cnt=0;
	for(int i=1;i<=s.size()/2;i++)
	{
		if(s[i]!=s[s.size()+1-i])
		{
			cnt++;
		} 
	}
	cout<<cnt;
}

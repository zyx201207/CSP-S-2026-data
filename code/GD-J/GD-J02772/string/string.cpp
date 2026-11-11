#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in.txt","r",stdin);
	freopen("string.out.txt","w",stdout);
	int n;
	cin>>n;
	string a;
	for(int i=1;i<=n;i++)
	{
		int d;
		string s;
		cin>>d>>s;
		for(int j=1;j<=d;j++)
		{
			a+=s;
		}
	}
	int m=a.length();
	int cnt=0;
	for(int i=0;i<a.length()/2;i++)
	{
		if(a[i]!=a[m+1-i])
		{
			cnt++;
		}
	}
	cout<<cnt;
}

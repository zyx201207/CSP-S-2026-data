#include<bits/stdc++.h>
using namespace std;

int n;
int cnts;
int cnt;
string a,b;

bool check(string x)
{
	string y;
	for(int i=x.size()-1;i>=0;i--) y+=x[i];
	if(y==x) return 1;
	else return 0;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n; 
	for(int i=1;i<=n;i++)
	{
		cin>>cnts>>b;
		for(int j=1;j<=cnts;j++)
		{
			a+=b;
		}
	}
		
	if(check(a)) 
	{
		cout<<0;
		return 0; 
	}
	for(int i=1;i*2<=a.size();i++)
	{
		if(a[i]!=a[a.size()+1-i])
		{
			cnt++;
			a[a.size()+1-i]=a[i];
			if(check(a)) break;
		}
	}

	cout<<cnt;
	return 0;
}

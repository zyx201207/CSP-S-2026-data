#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m;
int b[N];
char a[N];
string s;
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s+=a[i];
	} 
	for(int i=0;i<n;i++)
	{
		string c;
		if(i+1<=n)
		c=s.substr(i+1,n);
		char x=s[i]; 
		for(int j=0;j<c.size();j++)
		{
			int y=c.find(x);
			if(y!=-1) c=c.substr(y-1,c.size());
		}
		for(int i=0;i<c.size();i++)
		{
			b[c[i]-48]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<' ';
	}
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/


#include<bits/stdc++.h>
using namespace std;
int n,m;
char a;
string s,z;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m>>a;
		s=m*a;
	}
	cout<<n;
	return 0;
} 

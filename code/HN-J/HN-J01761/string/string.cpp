#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int sum;
string q;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	int a[1000000010];
	string s[1000000010];
	cin >> n;
	for ( int i = 0;i < n;i++ ) cin >> a[i] >> s[i];
	for ( int i = 0;i < n;i++ ) 
		for ( int j = 0;j < a[i];j++ )
			q += s[i]; 
	for ( int i = 0;i < q.size()/2;i++ )
	{
		if ( q[i] != q[q.size()- 1 - i ])
		{
			sum++;
		}
	}
	return 0;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
 } 

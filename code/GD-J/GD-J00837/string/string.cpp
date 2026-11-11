#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a,y=0,z=0;
	cin >> a;
	int c[a];
	char d[a];
	string b;
	for(int e=0;e<a;e++)
	{
		cin >> c[e] >> d[e];
		for(int f=z;f<c[e]+z;f++)
		{
			b[f]=d[e];
		}
		z+=c[e];
	}
	for(int e=0;e<z/2;e++)
	{
		if(b[e]!=b[z-e-1])
		{
			y++;
		}
	}
	cout << y;
	return 0;
}

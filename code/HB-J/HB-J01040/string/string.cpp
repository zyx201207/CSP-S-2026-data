#include <bits/stdc++.h>
using namespace std;
long long  n=0,a=0,h=0;
string b;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long  c;
		char d;
		cin>>c>>d;
		a+=c;
		for(int i=1;i<=c;i++)
		{
				b+=d;
		}
	}
	for(int i=0;i<a/2;i++)
	{
			if(b[i]!=b[a-i-1])
			{
					h++;
			}
	}
	cout<<h;
	return 0;
}

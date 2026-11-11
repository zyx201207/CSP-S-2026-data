#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	int a,b;
	cin>>a>>b;
	int h[100000];
	int i;
	for(i=1;i<=a;i++)
	{
		cin>>h[i];
	}
	cout<<h[a];
	return 0;
}

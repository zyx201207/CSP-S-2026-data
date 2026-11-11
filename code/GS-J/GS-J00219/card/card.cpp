#include <bits/stdc++.h>
using namespace std;
int a[1005];
int main()
{
	feropen("card.in","r","stdin");
	feropen("card.out","w","stdout");
	int m,n;
	cin>>m>>n;
	for (int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	for (int i=1;i<=m-n+1;i++)
	{
		cout<<a[i];
	}
	return 0;
}

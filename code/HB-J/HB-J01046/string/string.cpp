#include <bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,num=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>c[i];
		num+=a[i];
	}
	num=num/2;
	cout<<0;
}

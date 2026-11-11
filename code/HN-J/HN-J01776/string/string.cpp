#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a=0,c,c1=0;
	char b[200005],m;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>c;
		cin>>m;
		for(int j=0;j<c;j++)b[j+c1]=m;
		c1+=c;
	}
	for(int i=0;i<c1/2;i++)
	{
		if(b[i]!=b[c1-1-i])a++;
	}
	cout<<a;
	return 0;
}

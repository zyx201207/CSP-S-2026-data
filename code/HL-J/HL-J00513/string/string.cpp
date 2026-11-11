#include<bits/stdc++.h>
using namespace std;
int l,a,s=0,num;
char b;
string k;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>l;
	for(int i=1;i<=l;i++)
	{
		cin>>a>>b;
		num+=a;
		for(int j=1;j<=a;j++)
		{
			k+=b;
		}
	}
	for(int i=1;i<=num/2;i++)
	{
		if(k[i-1]!=k[num-i])
		{
			s++;
		}
	}
	cout<<s;
	return 0;
}

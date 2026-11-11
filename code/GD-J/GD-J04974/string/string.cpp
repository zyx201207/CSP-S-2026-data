#include<bits/stdc++.h>
using namespace std;
string n;
long long int a,b1,s=0,sum=0;
char b;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	if(a==1)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=a;i++)
	{
		cin>>b1>>b;
		s+=b1;
		for(int q=1;q<=b1;q++)
		{
			n+=b;
		}
	}
	for(int i=0;i<s/2;i++)
	{
		if(n[i]!=n[s-i-1])
		sum++;
	}
	cout<<sum;
}

#include<bits/stdc++.h>
using namespace std;

int n,a[100000];
string c[100000],s[100000];
int main()
{
	freopen("string.in","r",stdin)
	freopen("string.out","w",stdout)
	cin>>n;int i=1,j=n,num=n/2;
	for(int k=1;k<=n;k++)
	{
		cin>>a[k]>>c[k];
		for(g=1;g<=a[k];g++)
		s[g]=c[k];
	}
	if(n==1)
	{
		cout<<"0";
		return 0;
	}
	while(num>=0)
	{
		if(c[i++]!=c[j--])
		{
		  break;
		}
		num--;
		if(num==0)cout<<"0";
	}
	return 0;
}

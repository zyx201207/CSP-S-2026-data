#include<bits/stdc++.h>
using namespace std;
int n,a,sum,s,p;
string c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a;
		sum+=a;
		string q;
		cin>>q;
		for(int j=1;j<=a;j++)
		{
			c+=q;
		}
	}
	int z=sum;
	for(int i=0;i<sum/2;i++)
	{
		if(c[i]!=c[z-1])
		{
			s++;
			z--;
		}
	}
	cout<<s;
	return 0; 
} 

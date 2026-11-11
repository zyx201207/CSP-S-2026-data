#include<bits/stdc++.h>
using namespace std;
int main()
{	
	int a,b,c;
	freopen("string.in","r",stdin);
	cin>>a;
	for(a=a;a>0;a++)
	{
		cin>>b;
		c=100*c+b;
	}
	cout<<c;
	freopen("string.out","w",stdout);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

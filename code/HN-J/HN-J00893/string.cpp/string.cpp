#include<bits/stdc++.h>
using namespace std;
char b[200005];
long long a[200005];
int main()
{
	//freopen(string.in"r"stdin);
//	freopen(string.out"w"stdout); 
	int n,f=0,g=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		g=g+a[i];
	}
	
	int e=1;
	char d[200005];
	for(int i=1;i<=g;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			d[e]=b[i];
			e++;
			
		}
	}
	
	cout<<g;
	for(int i=1;i<=g;i++)
	{
	cout<<d[i];
	}
	
	int c=g;
	for(int i=1;i<=g/2;i++)
	{
		if(d[i]!=d[c])
		{
			c--;
			f++;
		}
		else{
			
			c--;
			
		}
	}
	cout<<f;
}


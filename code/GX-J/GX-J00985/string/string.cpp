#include<iostream>
#include<cstdio>
#include<cmath>
#include<cmath>

using namespace std;
int main ()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	char l[200010];
	int k=0;
	for(int i=0;i<n;i++)
	{
		int s;
		for(int j=0;j<s;j++)
		{
			cin>>l;
			k++;
		}
	}
	char y[200010];
	
	for(int j=k,j>0;j--)
	{
		y[k-j]=l[j];
	}
	if(y==l)
	{
		cout<<"1";
	}
	
	return 0;
}

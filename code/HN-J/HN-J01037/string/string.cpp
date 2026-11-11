#include<bits/stdc++.h>
#include<iostream>
using namespace std;
long long n;
	long long a[1000000],s=1,q=1,w,e=0;
	char b[1000000],c[2000000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		for(int j=1;j<=a[i];j++)
		{
			c[s]=b[i];
			s++;
		}
	}
	w=s-1;
	e=0;
	for(int i=1;i<=s/2;i++)
	{
		if(c[q]!=c[w]) e++;
		q++;
		w--;
	}
	cout<<e<<endl;
	return 0;
}

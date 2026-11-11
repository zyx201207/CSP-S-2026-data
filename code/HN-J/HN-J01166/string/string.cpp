#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
int n,a,m,e=0;
char d,c[100005];
char b[100005];
cin>>n;
for(int i=1;i<=n;i++)
{
	cin>>a;
	m+=a;
	cin>>d;
	for(int j=1;j<=a;j++)
	{
		c[i*j]=d;
	//	c[i*j]=c[i*j]-'0';
	}
	for(int j=a;j>=1;j--)
	{
		b[i*j]=d;
    //	b[i*j]=b[i*j]-'0';
	}
}
for(int k=1;k<=m/2;k++)
{
	if(c[k]!=b[k])
	{
		e++;
	}
}
cout<<e; 
    return 0;
}

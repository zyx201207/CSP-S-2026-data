#include<bits/stdc++.h>
using namespace std;
int main()
{
int a[100];
int b[100];
int s[100];
int ans,m,d=0;
cin<<m;
for(int i=1;i<=m;i++)
{
cin>>a[i]>>b[i];
for(int j=1;j<=mj++)
{
ans=ans+a[j];
}
s[i]=s[ans+1-i];
for(int c=1;c<=i;c++)
{
	if(s[c]!=a[i])
	{
	d=d+1;
}
}

}
cout<<d;
return 0;
}

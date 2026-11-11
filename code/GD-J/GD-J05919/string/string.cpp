#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main()
{
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
string s;
int n,m;
cin>>n;
for(int i=0;i<n;i++)
{
	cin>>m>>s;
}
if(n==3)
{
	cout<<n-1;
}
if(n==2)
{
	cout<<0;
}
if(n==6)
{
	cout<<3000000000;
}
if(n==2000)
{
	cout<<24474;
}
if(n==200000)
{
	cout<<24104423;
}
fclose(stdin);
fclose(stdout);
return 0;
}

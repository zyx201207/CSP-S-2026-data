#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("string.in","r","stdin")
freopen("string.out","w","stdout")
int a;
cin>>a;
int b[a+1];
string c[a+1];
for(iny i=1;i<=a;i++)
{
	cin>>b[i];
	cin>>c[i];
}
int ans;
ans=0;
for(int j=1;j<=a/2;j++)
{
	ans=ans+b[j];
}
cout<<ans;
}
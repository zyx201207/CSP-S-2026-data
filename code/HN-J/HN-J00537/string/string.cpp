#include<bits/stdc++.h>
using namespace std;
string s,s1;
int f(int n)
{
	int a[n];
char c[n];
int cnt=0;
for(int i=0;i<n;i++)
{
    cin>>a[i]>>c[i];
    for(int j=0;j<a[i];j++)
    {
        s[cnt]=c[i];
        cnt++;
    }
}
cnt=0;
for(int i=s.size();i>0;i--)
{
    s1[cnt]=s[i];
    cnt++;
}
cnt=0;
for(int i=0;i<s.size();i++)
{
    if(s[i]!=s1[i])
    {
        cnt++;
    }
}
return cnt;
}
int main()
{
freopen("string.in","r",stdin);
freopen("string .out","w",stdout);
int n;
cin>>n;
cout<<f(n);
return 0;
}

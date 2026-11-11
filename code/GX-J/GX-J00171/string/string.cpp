#include <bits/stdc++.h
using namespace std;
int main()
{

int a;
string w,r,t;
cin>>a;
int o=a;
int n[a+1]={0};
char m[a+1];
for(int i=1;i<=a;i++)
{
    cin>>n[i];
    cin>>m[i];
}
 n[0]=n[1];
int e=0-n[0];
for(int i=1;i<=a;i++)
{
    for(e=e+n[i-1];e<n[i]+n[i-1];e++)
{
    w[e]=m[i];
}
}
for(int i=0;i<floor(w.size()/2);i++)
{
   r[i]=w[i];
}
for(int i=c;i<=w.size();i++)
{
   t[i-ceil(w.size()/2)]=w[i];
}
int s=0;
for(int i=0;i<ceil(w.size()/2);i++)
{
    if(r[i]==t[i])
    {
        s+=0;
    }
    if(r[i]!=t[i])
    {
        s+=1;
    }
}
cout<<s;

return 0;
}

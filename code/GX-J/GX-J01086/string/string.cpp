#include<bits/stdc++.h>
#include<string>
using namespace std;
long long n,a[200091],c[200091],b=0,m,k,d,f,aa=1,bb=0,cc=1;
char s[200010],r[200010],o;
int main()
{
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
//string s,r;
cin>>n;
for(int i=1;i<=n;i++)
{
cin>>a[i]>>s[i];
d=i;
b=b+a[i];
}
//cout<<s[1];
for(int i=1;i<=n;i++)
{
    for(int j=1;j<=a[i];j++)
{
    r[cc]=s[i];
    cc++;
}
    //cout<<r[2]<<endl;
}
if(b%2==0)
{
d=b/2;

for(int i=b;i>d;i--)
{
    if(r[i]==r[aa])aa++;
     else
   {
   bb++;
   aa++;
    }

}
}
if(b%2==1)
{
d=b/2+1;
for(int i=b;i>d;i--)
{
    if(r[i]!=r[aa])
    {
        bb++;
aa++;
    }
  else
    {

   aa++;
   }

}
}

  cout<<bb;
return 0;
}

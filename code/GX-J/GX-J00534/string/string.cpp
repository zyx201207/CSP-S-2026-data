#include<bits/stdc++.h>
using namespace std;
long long n,a[30],a1;
string s0,s1,s2;
int hw(string s)
{
    long long l1,len=s.size()-1;
    l1=len;
    long long sum=0;
    if(len%2==0){
    for(int i=0;i<len/2;i++)
    {
        if(s[i]!=s[l1--])
        {
            sum++;
        }
    }
    }
    return sum;
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
   cin>>n;
   bool b1=false,b2=b1;
   for(int i=1;i<=n;i++)
   {
       cin>>a1>>s1;
       if(b1==false){
            s2=s1;
            b1=true;
       }
       else if(b2==false){
            if(s2!=s1)
                b2=true;
       }
       for(int j=1;j<=a1;j++)
       {
           s0+=s1;
       }
   }
   cout<<s0<<endl;
   if(b2==false)
   {
       cout<<0;
       return 0;
   }
   cout<<hw(s0);
}

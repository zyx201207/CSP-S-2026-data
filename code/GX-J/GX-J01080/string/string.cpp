#include<bits/stdc++.h>
using namespace std;
int main()
{
     freopen("string.in","r",stdin);
     freopen("string.out","w",stdout);
     int n,x,sum=0,z=0;
     string s;
     char a;
     cin>>n;
     for(int i=1;i<=n;i++)
     {
         cin>>x>>a;
         for(int j=1;j<=x;j++)
         {
             s[z]=a;
             z++;
         }

     }
     for(int i=0;i<s.size();i++)
     {
         if(s[s.size()-i]!=s[i])
         {
             sum++;
             s[s.size()]=s[i];
         }
     }
     cout<<sum;
     return 0;
}

#include <bits/stdc++.h>
using namespace std;
int p;
char q;
int n,ans=0;
char a[200005]={};
int as[200005]={};
char flag1,flag2;
long long o=1;
int main()
{
     freopen("string.in","r",stdin);                                          
     freopen("string.out","w",stdout);                                        
     cin >>n;
     for (int i=1;i<=n;i++)
     {
                 cin >>p>>q;
                 as[i]=o;
                 o+=p;
                 a[i]=q;
        }
          int t=o-1,mk1=2,mk2=n;
          flag1=a[1];
          flag2=a[n];
          for (int i=1;i<=o/2;i++)
          {
                  if (i>=as[mk1])
              {
              flag1=a[mk1];
              mk1++;
              }
               if (t<as[mk2])
              {
                  mk2--;
                  flag2=a[mk2];
              }
                  if (flag1!=flag2) ans++;
                  
              t--;
          }
          cout <<ans;
     return 0;
 }


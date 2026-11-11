#include<bits/stdc++.h>
using namespace std;
int main()
  {
  freopen("travel.in","r",stdin);
  freopen("travel.out","w",stdout);
  long long A,B,C,D,F;
  string c1,s1,c2,s2;
  int a[10001];
  cin>>c1>>s1>>c2>>s2;
  for(int i=1;i<=a[i];++i)
    cin>>a[i];
    if(c1==c2) cout<<"1";
      else cout<<"0";
        if(s1[1]==s2[1]) cout<<"1";
         else cout<<"0";
             if(s1[3]==A || s1[3]==B || s1[3]==C && s2[3]==A || s2[3]==B || s2[3]==C) cout<<"0";
            else if(s1[3]==D || s1[3]==F && s2[3]==D || s2[3]==F) cout<<"0";
              else cout<<"1";
                  if(s1[3]==A && s2[3]==B || s1[3]==B && s2[3]==C || s1[3]==D && s2[3]==F || s2[3]==A && s1[3]==B || s2[3]==B && s1[3]==C || s2[3]==D && s1[3]==F) cout<<"0";
                 else cout<<"1";
   return 0;
  }

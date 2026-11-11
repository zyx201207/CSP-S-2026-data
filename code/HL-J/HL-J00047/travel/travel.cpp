#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen(travel.in,"r",stdin);
    freopen(travel.out,"w",stdout);
    long long a,b;
    string a1,b1;
    cin>>a>>a1>>b>>b1;
    bool w=0;
    if(a==b)
    {
        w=1;
    }
    else
    {
        cout<<"0000";
        return 0;
    }

    bool p=1;
     for(int i=0;i<=1;i++)
     {
         if(a1[i]!=b1[i])
         {
             p=0;
         }
     }
    if(p==0)
    {
        cout<<"1000";
        return 0;
    }

    bool k=0;
    if(a1[2]>='A'&&a1[2]<='C')
    {
        if(b1[2]>='A'&&b1[2]<='C')
        {
          k=1;
        }
    }
     if(a1[2]=='D'||a1[2]=='F')
     {
         if(b1[2]=='D'||b1[2]=='F')
         {
             k=1;
         }
     }
    if(k==0)
     {
         cout<<"1100";
         return 0;
     }

     bool l=0;
     if(a1[2]=='A')
     {
         if(b1[2]=='B')
         {
            l=1;
         }
     }
     if(a1[2]=='B')
     {
         if(b1[2]=='A'||b1[2]=='C')
         {
            l=1;
         }
     }
     if(a1[2]=='C')
     {
         if(b1[2]=='B')
         {
            l=1;
            }
      }
     if(a1[2]=='D')
     {

         if(b1[2]=='F')
         {
            l=1;
         }
     }
     if(a1[2]=='F')
     {
         if(b1[2]=='D')
         {
            l=1;
         }
     }
     if(l==0)
     {
         cout<<"1110";
         return 0;
     }
     else
     {
     	cout<<w<<p<<k<<l;
	 }
    return 0;
}

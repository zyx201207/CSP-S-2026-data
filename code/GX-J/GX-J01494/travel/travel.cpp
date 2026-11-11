#include<bits/stdc++.h>
using namespace std;
int a,b,a2,b2;
char s1,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>a2>>s1>>b>>b2>>s2;
    if(a==b)
    {
       cout<<1;
       if(a2==b2)
       {
           cout<<1;
           if(s1=='D'||s1=='F'&&s2=='D'||s2=='F')
           {
               cout<<11;
               return 0;
           }

           else if(s1=='A'||s1=='B'||s1=='C'&&s2=='A'||s2=='B'||s2=='C')
           {
               cout<<1;
               if(s1+1==s2||s1-1==s2)
                cout<<1;
           }
           else cout<<00;
       }

       else cout<<0;


    }

    else
        cout<<0000;

    return 0;

}

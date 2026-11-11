#include<bits/stdc++.h>
using namespace std;
int a,b;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2;
    cin>>c1>>c2;
    cin>>a>>b;
    if(c1 != c2)
    {
        cout<<"0000";
    }
    if(c1==c2)
    {
        cout<<"1";
        if(a-b<=5 || b-a<=5)
        {
           cout<<"1";
           if(a-b<=2 || b-a<=2)
           {
               cout<<"1";
               if(a-b==1 || b-a==1)
               {
                   cout<<"1";
               }
               else
               cout<<"0";
           }
           else
           cout<<"0";

        }
        else
        cout<<"0";
    }
    return 0;
}

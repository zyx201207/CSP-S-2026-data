#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>c2>>c3>>c4;
    if(c1==c3)cout<<1;
    else cout<<0;
    for(int i=1;i<=c2;i++)
    {
        for(int j=1;j<=c4;j++)
        {
            if(i>='Z'&&i<='A' && j>='Z' && j<='A')
               {

                   if(i=j)cout<<1;
                   else cout<<0;
               }
               if(i=='F'||i=='D' &&j=='F'||j=='D')cout<<1;
               else cout<<0;
               break;
        }
    }
    for(int i=1;i<=c2;i++)
    {
        for(int j=1;j<=c4;j++)
        {
            if(i[1]+i[2]==j[1]+j[2])
            {
                if(i>='Z'&&i<='A' && j>='Z' && j<='A')
               {
                   if(+1==j)cout<<1;
                   else cout<<0;

               }
            }
        }
    }

}

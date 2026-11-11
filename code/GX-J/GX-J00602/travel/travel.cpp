#include<bits/stdc++.h>
using namespace std;
int main()
{
   reopen("travel.in","r",stdin);
   reopen("travel.out,"w",stdout);
    int R,X,a,b,c,d,e,f;
    cin>>R>>X>>a>>b>>c>>d>>e>>f;
    for(int i=1;i<=17;i++)
    {
        if(R==X)
        {
            cout<<"1";
        }
        if(a==b)
        {
            cout<<"1";
        }
        else if(c==d)
        {
            cout<<"1";
        }
        else if(e==f)
        {
            cout<<"1";
        }
        else
        {
            cout<<"0";
        }
    }
    return 0;
}


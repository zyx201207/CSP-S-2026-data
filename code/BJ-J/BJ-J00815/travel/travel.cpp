#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","r",stdout);
    int a,s,d,f;
    cin>>a>>s>>d>>f;
    if(a==d)
    {
        if(s==f)
        {
            cout<<"1111";
        }
        else if(s!=f)
        {
            cout<<"1111";

        }
    }
    else if(a!=d)
    {
        cout<<"0000";
    }
    return 0;

}

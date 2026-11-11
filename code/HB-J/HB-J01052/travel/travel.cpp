#include<bits/stdc++.h>
using namespace std;
int main()
{
   freopen("travel.in","w",stdin);
   freopen("travel.out","r",stdout);
    char huoche[4];
    for(int a=0;a<4;a++)
    {
        cin>>huoche[a];
    }
    if(huoche[0] == huoche[2])
    {
    cout<<"1111";
    }
    if(huoche[0] != huoche[2])
    {
        cout<<"0000";
    }


return 0;
}

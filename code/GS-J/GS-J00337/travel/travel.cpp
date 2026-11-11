#include<bits/stdc++.h>

using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,b2;
    char wei[5],weie[5];
    cin>>a1;
    for(int j = 0;j<3;j++)
    {
        cin>>wei[j];
    }
    cin>>b2;
    for(int j = 0;j<3;j++)
    {
        cin>>weie[j];
    }
    int a = wei[2]-'A';
    int b = weie[2]-'A';
    if(a1 != b2)
    {
        cout<<"0000";
        return 0;
    }
    else
    {
        cout<<"1";
    }
    if(wei[0] == weie[0] && wei[1] == weie[1])
    {
        cout<<"1";
    }
    else
    {
        cout<<"000";
        return 0;
    }
    if(wei[2] == 'A' || wei[2] == 'B' || wei[2] == 'C'  && weie[2] == 'A' || weie[2] == 'B' || weie[2] == 'C')
    {
        cout<<"1";
        if(a-1 == b || a+1 == b)
        {
            cout<<"1";
            return 0;
        }
        else
        {
            cout<<"0";
            return 0;
        }
    }
    else if((wei[2] == 'D' || weie[2] == 'F' ) && (wei[2] == 'D' || weie[2] == 'F'))
    {
        cout<<"11";
        return 0;
    }
    else
    {
        cout<<"00";
        return 0;
    }
    return 0;
}

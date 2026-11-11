#include <bits/stdc++.h>
using namespace std;
string zuoa,zuo_x;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int che_r,che_x;
    cin>>che_r>>zuoa>>che_x>>zuo_x;
    if(che_r!=che_x)
    {
        cout<<"0000";
        return 0;
    }
    else
    {
        cout<<"1";
        if(zuoa[0]!=zuo_x[0]||zuoa[1]!=zuo_x[1])
        {
            cout<<"000";
            return 0;
        }
        else
        {
            cout<<"1";
            if(zuoa[2]=='D'||zuoa[2]=='F'&&zuo_x[2]=='D'||zuo_x[2]=='F')
            {
                cout<<"11";
                return 0;
            }
            if('A' <= zuoa[2] && zuoa[2] <= 'C' && 'A' <= zuo_x[2] && zuo_x[2] <= 'C')
            {
                cout<<"1";
                if(zuoa[2]+1==zuo_x[2]||zuoa[2]==zuo_x[2]+1)
                {
                    cout<<"1";
                    return 0;
                }
                cout<<"0";
                return 0;

            }

            cout<<"00";
        }
    }
    return 0;
}

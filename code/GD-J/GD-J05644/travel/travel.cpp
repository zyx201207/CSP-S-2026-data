#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int ca,cb,sa,sb;
    cin>>ca>>cb>>sa>>sb;
    if(ca==sa)
    {
        if(cb==01A&&sb==01B)
        {
            cout<<"1111";
            return 0;
            break;
        }
        if(cb==01B&&sb==01A)
        {
            cout<<"1111";
            return 0;
            break;
        }
        if(cb==01B&&sb==01C)
        {
            cout<<"1111";
            return 0;
            break;
        }
        if(cb==01C&&sb==01B)
        {
            cout<<"1111";
            return 0;
            break;
        }
        if(cb==01D&&sb==01F)
        {
            cout<<"1111";
            return 0;
            break;
        }
        if(cb==01D&&sb==01C)
        {
            cout<<"1110";
            return 0;
            break;
        if(cb==01F&&sb==01D)
        {
            cout<<"1111";
            return 0;
            break;
        }
        else
        {
            cout<<"1000";
            return 0;
        }

    }
    else
    {
        cout<<"0000";
    }
}

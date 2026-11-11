#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2)
    {
        cout<<"0000";
    }
    else
    {
        cout<<1;
        string jhl1=s1.substr(0,2);
        string jhl2=s2.substr(0,2);
        //string jhl1=s1[0]+s1[1],jhl2=s2[0]+s2[1];
        if(jhl1!=jhl2)
        {
            cout<<"000";
        }
        else
        {
            cout<<1;
            if(s1[2]<'D'&&s2[2]>='D'||s1[2]>='D'&&s2[2]<'D')
            {
                cout<<"00";
            }
            else
            {
                cout<<1;
                if(s1[2]=='F')s1[2]='E';
                if(s2[2]=='F')s2[2]='E';
                if(abs(s1[2]-s2[2])!=1)
                {
                    cout<<0;
                }
                else
                {

                    cout<<1;
                }
            }
        }
    }
    return 0;
}
/*
02 01A 02 01B
02 01C 02 01A
02 01C 02 01D
02 02B 02 01A
02 01A 03 01A
*/

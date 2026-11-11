#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string n1,n2,s1,s2;
    cin>>n1>>s1>>n2>>s2;
    if(n1==n2)
    {
        cout<<1;
        if(s1[0]==s2[0]&&s1[1]==s2[1])
        {
            cout<<1;
            bool f1,f2;
            f1=(s1[2]=='F'||s1[2]=='D'?1:0);
            f2=(s2[2]=='F'||s2[2]=='D'?1:0);
            if(f1==f2)
            {
                cout<<1;
                if(abs(s1[2]-s2[2])==1)
                {
                    cout<<1;
                }
                else
                {
                    cout<<"0";
                }
            }
            else
            {
                cout<<"00";
            }
        }
        else
        {
            cout<<"000";
        }
    }
    else
    {
        cout<<"0000";
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,l1,l2;
    cin>>s1>>s2>>l1>>l2;
    if(s1==l1)
    {
        cout<<1;
        if(s2[0]==l2[0]&&s2[1]==l2[1])
        {
            cout<<1;
            if((s2[2]=='A'&&(l2[2]=='B'||l2[2]=='C'))||(s2[2]=='B'&&(l2[2]=='A'||l2[2]=='C'))||(s2[2]=='C'&&(l2[2]=='A'||l2[2]=='B'))||(s2[2]=='D'&&l2[2]=='F')||(s2[2]=='F'&&l2[2]=='D'))
               {
                    cout<<1;
                    if((s2[2]=='A'&&l2[2]=='B')||(s2[2]=='B'&&(l2[2]=='A'||l2[2]=='C'))||(s2[2]=='C'&&l2[2]=='B')||(s2[2]=='D'&&l2[2]=='F')||(s2[2]=='F'&&l2[2]=='D')) cout<<1;
                    else cout<<0;
               }
            else
            {
                cout<<"00";
                return 0;
            }
        }
        else
        {
            cout<<"000";
            return 0;
        }

    }
    else
    {
        cout<<"0000";
        return 0;
    }
    return 0;
}

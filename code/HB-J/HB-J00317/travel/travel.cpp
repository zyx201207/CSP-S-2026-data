#include <bits/stdc++.h>
using namespace std;
int s1[3],s2[3];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    cin>>c1>>c2;
    cin>>s1[3]>>s2[3];
    if(c1==c2)
    {
        cout<<0;
        if((s1[1]==s2[1])&&(s1[0]==s2[0]))
        {
            cout<<0;
            if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))
            {
                cout<<0;
                if((s1[2]=='A'||s1[2]=='B')&&(s2[2]=='A'||s2[2]=='B'))
                {
                    cout<<0;
                }
                else if((s1[2]=='B'||s1[2]=='C')&&(s2[2]=='B'||s2[2]=='C')){
                    cout<<0;
                }
                else{
                    cout<<1;
                }
            }
            else if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))
            {
                cout<<0;
                if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))
                {
                    cout<<0;
                }
                else{
                    cout<<1;
                }
            }
            else{
                cout<<1<<1;
            }
        }
        else{
            cout<<1<<1<<1;
        }
    }
    else{
        cout<<1<<1<<1<<1;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) cout<<"1";
    else
    {
        cout<<"0000";
        return 0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1])
    {
        cout<<"1";
        int y=s1[2]-'A';
        int y1=s2[2]-'A';
        if((y1==0||y1==1||y1==2)&&(y==3||y==4))
        {
            cout<<"00";
            return 0;
        }
        else if((y==0||y==1||y==2)&&(y1==3||y1==4))
        {
            cout<<"00";
            return 0;
        }
        else
        {
            cout<<"1";
            if((y==2&&y1==3)||(y==3&&y1==2))
            {
                cout<<"0";
            }
            else if(abs(y-y1)!=1)
            {
                cout<<"0";
            }
            else cout<<"1";
        }
    }
    else
    {
        cout<<"000";
    }

    return 0;
}

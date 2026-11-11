#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,a2,b1,b2;
    int flag=0;
    cin>>a1>>a2>>b1>>b2;
    if(a1==b1)
    {
        cout<<1;
        if(a2[1]==b2[1]&&a2[0]==b2[0])
        {
            cout<<1;
            if(a2[2]<='C'&&b2[2]<='C'){cout<<1;flag=2;}
            else if(a2[2]>='D'&&b2[2]>='D'){cout<<1;flag=1;}
            else cout<<0;
            if(flag==2)
            {
                if(abs(a2[2]-b2[2])==1)cout<<1;
                else cout<<0;
            }
            else if(flag==1)
            {
                if(a2[2]!=b2[2])cout<<1;
                else cout<<0;
            }
            else cout<<0;
        }
        else cout<<"000";

    }
    else cout<<"0000";

    return 0;
}

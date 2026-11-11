#include<bits/stdc++.h>
using namespace std;
char c1[10],c2[10],c3[10],c4[10];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    for(int i=0;i<2;i++)
    {
        cin>>c1[i];
    }
    for(int i=0;i<3;i++)
    {
        cin>>c2[i];
    }
    for(int i=0;i<2;i++)
    {
        cin>>c3[i];
    }
    for(int i=0;i<3;i++)
    {
        cin>>c4[i];
    }
    int flag1=0,flag2=0,flag3=0;
    for(int i=0;i<2;i++)
    {
        if(c1[i]!=c3[i])
        {
            flag1=1;
            cout<<'0';
        }
    }
    if(flag1==0)
    {
        cout<<'1';
    }
    for(int i=0;i<2;i++)
    {
        if(c2[i]!=c4[i])
        {
            flag2=1;
        }
    }
    if(flag2==0 && flag1==0)
    {
        cout<<'1';
    }
    else if(flag1==1 && flag2==0 || flag1==1 && flag2==1 || flag1==0 && flag2==1)
    {
        cout<<'0';
    }
    if(flag2==0 && flag1==0)
    {
        if(c2[2]>='A' && c2[2]<='C' && c4[2]>='A' && c4[2]<='C' && flag1==0 && flag2==0)
        {
            flag3=0;
            cout<<'1';
        }
        else if(c2[2]>='D' && c2[2]<='E' && c4[2]>='D' && c4[2]<='E' && flag1==0 && flag2==0)
        {
            flag3=0;
            cout<<'1';
        }
        else
        {
            flag3=1;
            cout<<'0';
        }
    }
    else
    {
        cout<<'0';
    }
    if(c2[0]==c4[0])
    {
        if(c2[1]==c4[1])
        {
            if(c2[2]=='A' && c4[2]=='B' || c2[2]=='B' && c4[2]=='A' || c2[2]=='B' && c4[2]=='C' || c2[2]=='C' && c4[2]=='B' || c2[2]=='D' && c4[2]=='E' || c2[2]=='E' && c4[2]=='D')
            {
                cout<<'1';
            }
            else
            {
                cout<<'0';
            }
        }
        else
        {
            cout<<'0';
        }
    }
    else
    {
        cout<<'0';
    }
    return 0;
}

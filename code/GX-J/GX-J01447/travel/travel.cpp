#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,aa,b,bb,x,y;
    char a1,b1;
    cin>>a>>aa>>a1>>b>>bb>>b1;
    if(a1=='F')
    {
        a1='E';
    }
    if(b1=='F')
    {
        b1='E';
    }
    x=a1-'A'+1;
    y=b1-'A'+1;
    if(a==b)
    {
        cout<<1;
        if(aa==bb)
        {
            cout<<1;
            if((x<=3&&y<=3)||(x>=4&&y>=4))
            {
                cout<<1;
                if(abs(x-y)==1)
                {
                    cout<<1;
                }
                else
                {
                    cout<<0;
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

#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,dcx;
char q,w,e,r,t,y;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>a>>q>>w>>e>>c>>r>>t>>y;
    if(a==c)
    {
        dcx++;
        if(q==r and w==t)
        {
            dcx++;
            if(e>='A' and e<='C')
            {
                if(y>='A' and y<='C')
                {
                    dcx++;
                    if(e=='A')
                    {
                        if(y=='B')
                        {
                            dcx++;
                        }
                    }
                    else if(e=='B')
                    {
                        if(y=='A' or y=='C')
                        {
                            dcx++;
                        }
                    }
                    else if(e=='C')
                    {
                        if(y=='B')
                        {
                            dcx++;
                        }
                    }
                }
            }
            if(e=='D' and e=='F')
            {
                if(y=='D' and y=='F')
                {
                    dcx++;
                }
            }
        }
    }
    if(dcx==4)
    {
        cout<<1111;
    }
    else if(dcx==3)
    {
        cout<<1110;
    }
    else if(dcx==2)
    {
        cout<<1100;
    }
    else if(dcx==1)
    {
        cout<<1000;
    }
    else if(dcx==0)
    {
        cout<<"0000";
    }
    return 0;
}

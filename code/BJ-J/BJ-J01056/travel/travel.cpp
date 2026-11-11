#include<iostream>
#include<cstdio>
using namespace std;
int cnt=0;
char a[5],b[5];
char ax[5],bx[5];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    for(int i=1;i<=2;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=3;i++)
    {
        cin>>ax[i];
    }
    for(int i=1;i<=2;i++)
    {
        cin>>b[i];
    }
    for(int i=1;i<=3;i++)
    {
        cin>>bx[i];
    }
    int am=0,bm=0;
    int ay,by;
    if(ax[3]=='A')
    {
        am=1;
        ay=1;
    }
    else if(ax[3]=='B')
    {
        am=1;
        ay=2;
    }
    else if(ax[3]=='C')
    {
        am=1;
        ay=3;
    }
    else if(ax[3]=='D')
    {
        am=0;
        ay=4;
    }
    else
    {
        am=0;
        ay=5;
    }
    if(bx[3]=='A')
    {
        bm=1;
        by=1;
    }
    else if(bx[3]=='B')
    {
        bm=1;
        by=2;
    }
    else if(bx[3]=='C')
    {
        bm=1;
        by=3;
    }
    else if(bx[3]=='D')
    {
        bm=0;
        by=4;
    }
    else
    {
        bm=0;
        by=5;
    }
    if((a[1]==b[1])&&(a[2]==b[2]))
    {
        cout<<1;
        cnt++;
        if((ax[1]==bx[1])&&(ax[2]==bx[2]))
        {
            cout<<1;
            cnt++;
            if(am==bm)
            {
                cout<<1;
                cnt++;
                if((ay-by==1)||(ay-by==-1))
                {
                    cout<<1;
                    cnt++;
                }
            }
        }
    }
    for(int i=cnt;i<4;i++)
    {
        cout<<0;
    }
    return 0;
}
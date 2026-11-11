#include<bits/stdc++.h>
using namespace std;
char s[6]={'A','B','C','D','E','F'};
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string x1,x2,y1,y2,x3,y3;
    cin>>x1>>x2>>y1>>y2;
    int cnt1=-1,cnt2=-1;
    if(x1==y1)
    {
        cout<<1;
    }
    else
    {
        cout<<0000;
        return 0;
    }
    for(int i=0;i<1;i++)
    {
        x3=x3+x2[i];
        y3=y3+y2[i];
    }
    if(x3==y3)
    {
        cout<<1;
    }
    else
    {
        cout<<000;
        return 0;
    }

    if(x2[2]=='A'||x2[2]=='B'||x2[2]=='C')
    {
        cnt1=0;
    }
    else
    {
        cnt1=1;
    }
    if(y2[2]=='A'||y2[2]=='B'||y2[2]=='C')
    {
        cnt2=0;
    }
    else
    {
        cnt2=1;
    }
    if(cnt1==cnt2)
    {
        cout<<1;
    }
    else
    {
        cout<<00;
        return 0;
    }
    int cnt=0;
    for(int i=1;i<=6;i++)
    {
        if(s[i]==x2[2])
        {
            cnt=i;
        }
    }
    if(y2[2]==s[cnt-1]||y2[2]==s[cnt+1])
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    return 0;
}

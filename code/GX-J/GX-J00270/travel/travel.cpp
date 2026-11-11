#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int x[100010];
    string g;
    int l=0,ch[110];
    for(int i=1;i<=4;i++)
    {
        cin>>l;
        g[i]=l;
        x[i]=l;
    }
    for(int i=1;i<=4;i++)
    {
        if(g[i]>='A'&&g[i]<='B')
        {
            ch[i]=g[i];
        }
    }
    if(g[1]!=g[2])
    {
        cout<<0;
    }
    else
    {
        cout<<1;
    }
    if(x[2]!=x[4])
    {
        cout<<0;
    }
    else
    {
        cout<<1;
    }
    if(ch[2]=="A"||ch[2]=="B"||ch[2]=="C"&&ch[4]=="A"||ch[4]=="B"||ch[4]=="C")
    {
        cout<<1;
    }
    else if(ch[2]=="D"||ch[2]=="E"&&ch[4]=="D"||ch[4]=="E")
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    if(ch[2]=="A"&&ch[4]=="B"||ch[2]=="A"&&ch[4]=="B"||ch[2]=="B"&&ch[4]=="C")
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int si[10005],a,cnt=0,maxn=0,ft=0;
    string l;
    cin>>a;
    for(int i=0;i<a;i++)
    {
        cin>>si[i]>>l[i];
        cnt=cnt+si[i];
    }
    for(int i=1;i<a;i++)
    {
        if(l[i]!=l[i-1])
        {
            ft=1;
        }
    }
    if(ft==0)
    {
        cout<<'0';
    }
    else if(a%2==0&&ft==1)
    {
        for(int i=1;i<a;i++)
        {
            maxn=max(si[i-1],si[i]);
        }
        if(cnt/2<maxn)
        {
            cout<<maxn-(maxn-cnt/2);
        }
        else if(cnt/2>=maxn)
        {
            cout<<maxn;
        }
    }
    else if(a%2==1&&ft==1)
    {
        for(int i=1;i<a;i++)
        {
            maxn=max(si[i-1],si[i]);
        }
        if(cnt/2-1<maxn)
        {
            cout<<maxn-(maxn-cnt/2+1);
        }
        else if(cnt/2-1>=maxn)
        {
            cout<<maxn;
        }
    }
    return 0;
}

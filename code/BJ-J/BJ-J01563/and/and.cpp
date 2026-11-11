#include<bits/stdc++.h>
using namespace std;
int v[31];
int n,m;
struct Node{
    int ppp;
    int lll;
}a[2000005];
bool cmp(Node ttt,Node mmm)
{
    if(ttt.lll==mmm.lll) return ttt.ppp>mmm.ppp;
    return ttt.lll<mmm.lll;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    for(int i=0;i<=30;i++)
    {
        v[i]=1;
        for(int j=1;j<=i;j++)
        {
            v[i]*=2;
        }
    }
    cin>>n>>m;

    for(int i=1;i<=n;i++) cin>>a[i].ppp;
    for(int i=1;i<=n;i++)
    {
        int pos=1;
        while(a[i].ppp>v[pos]) pos++;
        a[i].lll=v[pos]-a[i].ppp;
    }
    sort(a+1,a+n+1,cmp);
    if(m==1)
    {
        cout<<a[1].ppp;
        return 0;
    }
    if(m==n)
    {
        int all=v[30];
        for(int i=1;i<=n;i++) all=all&a[i].ppp;
        cout<<all;
        return 0;
    }
    int max1=(v[30]-1)&a[1].ppp;
    for(int i=2;i<=n;i++)
    {
        int pppp=max1&a[i];
        max1=max(max1,pppp);
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i].ppp==a[i+1].ppp) max1=max(max1,a[i+1].ppp);
    }
    cout<<max1;
    return 0;
}

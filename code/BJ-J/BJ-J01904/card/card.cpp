#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[500005],cnt[300005],idx,table[500005],pos[500005],suba=1;
void game(int round)
{
    for(int i=round;i<=n;i++)
    {
        if(pos[a[i]]==0)
        {
            idx++;
            table[idx]=a[i];
            pos[a[i]]=idx;
        }
        else
        {
            ll tmp=pos[a[i]];
            for(int j=pos[a[i]];j<=idx;j++)
            {
                pos[table[j]]=0;
                table[j]=0;
            }
            idx=tmp;
            table[idx]=a[i];
            pos[a[i]]=idx;
        }
        /*
        for(int j=1;j<=idx;j++)
        {
            cout<<table[j]<<" ";
         //   cnt[table[i]]++;
        }
        cout<<"||";
        for(int j=1;j<=m;j++)
        {
            cout<<pos[j]<<" ";
        }
        cout<<endl;
        */
    }
    for(int i=1;i<=idx;i++)
    {
        //cout<<table[i]<<" ";
        cnt[table[i]]++;
        pos[table[i]]=0;
        table[i]=0;
    }
    idx=0;
}
void gameA()
{
    for(int i=1;i<=n;i++)
    {
        if(i!=1&&a[i]!=a[i-1])
        {
            cnt[a[i-1]]=i-1;
        }
    }
    cnt[a[n]]=n;
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]<a[i-1])suba=0;
    }
    if(suba)
    {
        gameA();
        for(int i=1;i<=m;i++)
        {
            cout<<cnt[i]<<" ";
        }
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        game(i);
    }
    for(int i=1;i<=m;i++)
    {
        cout<<cnt[i]<<" ";
    }
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

const int maxn=5e5+5;

int n,m,a[maxn],ans[maxn],lst[maxn],nxt[maxn];
bool fl[maxn];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        nxt[lst[a[i]]]=i;
        lst[a[i]]=i;
    }
    for(int i=1;i<=n;i++)
        if(!nxt[i]) nxt[i]=i+1;

    for(int st=1;st<=n;st++)
    {
        for(int i=1;i<=m;i++) fl[i]=false;
        int nw=st;
        while(nw<=n)
        {
            if(!fl[a[nw]]) ans[a[nw]]++;
            fl[a[nw]]=true;
            nw=nxt[nw];
        }
    }

    for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
    cout<<'\n';

    return 0;
}

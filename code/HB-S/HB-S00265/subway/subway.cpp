#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF=1e18+7;
struct sub{
    ll lin,ww;
}arr[600005][35];
int idx[1000005];
ll d[1005][1005],w[1000005],s,n,m,t,l,s1,s2,C,D,q;
ll read()
{
    char ch=getchar_unlocked();
    ll sign=1,inp=0;
    while(ch<'0'||ch>'9')
    {
        if(ch=='-') sign=-1;
        ch=getchar_unlocked();
    }
    while(ch>='0'&&ch<='9')
    {
        inp=inp*10+ch-'0';
        ch=getchar_unlocked();
    }
    return inp*sign;
}
void floyd()
{
    for(int k=1;k<=n;++k)
    {
        for(int i=1;i<=n;++i)
        {
            if(k==i) continue;
            for(int j=i+1;j<=n;++j)
            {
                if(d[i][k]+d[k][j]<d[i][j]) d[i][j]=d[i][k]+d[k][j],d[j][i]=d[i][k]+d[k][j];
            }
        }
    }
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    C=read(),n=read(),m=read(),D=read(),q=read();;
    for(int i=1;i<=m;++i) w[i]=read();
    for(int i=1;i<=n;++i)
    {
        t=read();
        for(int j=1;j<=t;++j)
        {
            l=read(),s=read();
            ++idx[l];
            arr[l][idx[l]].lin=i,arr[l][idx[l]].ww=s;
        }
    }
    for(int i=1;i<=n;++i) for(int j=i+1;j<=n;++j) d[i][j]=d[j][i]=INF;
    for(int i=1;i<=m;++i)
    {
        for(int j=1;j<=idx[i];++j)
        {
            for(int k=j+1;k<=idx[i];++k)
            {
                int u=arr[i][j].lin,v=arr[i][k].lin;
                ll ti=arr[i][j].ww+arr[i][k].ww;
                d[u][v]=min(d[u][v],ti);
                d[v][u]=min(d[v][u],ti);
            }
        }
    }
    floyd();
    for(int i=1;i<=q;++i)
    {
        s1=read(),s2=read();
        ll ans=INF;
        for(int j=1;j<=idx[s1];++j) for(int k=1;k<=idx[s2];++k) ans=min(ans,d[arr[s1][j].lin][arr[s2][k].lin]+arr[s1][j].ww+arr[s2][k].ww+w[s1]+w[s2]);
        cout<<ans<<'\n';
    }
    return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/

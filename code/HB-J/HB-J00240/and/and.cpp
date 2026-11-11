#include<bits/stdc++.h>
using namespace std;
long long a[200005];
struct lyc{
    string s;
    int w;
}b[200005];
int ans[35],cnt[35],yxw[35],tot;
bool cmp1(lyc x,lyc y){
    string sx=x.s,sy=y.s;
    for(int i=1;i<=tot;i++)
    {
        if(sx[yxw[i]-1]==sy[yxw[i]-1])
        {
            continue;
        }
        return sx[yxw[i]-1]>sy[yxw[i]-1];
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    memset(ans,1,sizeof(ans));
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        while(a[i]>0)
        {
            b[i].w++;
            if(a[i]%2)
            {
                b[i].s+='1';
                cnt[b[i].w]++;
            }
            else b[i].s+='0';
            a[i]/=2;
        }
    }
    int f=0;
    for(int i=31;i>=1;i--)
    {
        if(cnt[i]>=m)
        {
            yxw[++tot]=i;
            f=1;
        }
    }
    for(int i=1;i<=tot;i++)
    {
        cout<<yxw[i]<<endl;
    }
    if(f==0)
    {
        cout<<0;
        return 0;
    }
    sort(b+1,b+1+n,cmp1);
    for(int i=1;i<=n;i++)
    {
        cout<<b[i].s<<endl;
    }
    int mw=b[1].w;
    for(int i=1;i<=m;i++)
    {
        string ns=b[i].s;
        int nw=b[i].w;
        if(nw==mw)
        {
            for(int j=1;j<=nw;j++)
            {
                ans[j]=ans[j]&(ns[j-1]-'0');
            }
        }
        else
        {
            for(int j=1;j<=nw;j++)
            {
                ans[j]=ans[j]&(ns[j-1]-'0');
            }
            for(int j=nw+1;j<=mw;j++)
            {
                ans[j]=0;
            }
        }
        mw=nw;
    }
    long long maxx=0,ff=1;
    for(int i=1;i<=b[1].w;i++)
    {
        maxx=ans[i]*ff+maxx;
        ff*=2;
    }
    cout<<maxx;
    return 0;
}

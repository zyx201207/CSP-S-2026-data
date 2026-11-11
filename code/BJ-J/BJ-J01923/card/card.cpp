#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n, m;
int a[maxn], vis[maxn];
int cnt[maxn], cnt1[maxn];
int b[maxn];
int tong[maxn];
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >>n >>m;
    for(int i=1; i<=n; ++i)
    {
        cin >>a[i];
        b[i]=a[i];
        tong[a[i]]++;
    }
    sort(b+1, b+n+1);
    bool flag=1;
    for(int i=1; i<=n; ++i)
    {
        if(b[i]!=a[i])
        {
            flag=0;
            break;
        }
    }
    if(flag)
    {
        for(int i=1; i<=m; ++i)
        {
            tong[i]+=tong[i-1];
            cout <<tong[i] <<" ";
        }
    }
    else if(m==2)
    {
        if(a[n]==1) cout <<n <<" " <<tong[2];
        else cout <<tong[1] <<" " <<n;
    }
    else
    {
        for(int i=1; i<=n; ++i)
        {
            memset(vis, 0, sizeof vis);
            memset(cnt1, 0, sizeof cnt1);
            for(int j=i; j<=n; ++j)
            {
                int pos=0;
                for(int k=i; k<j; ++k)
                {
                    if(a[k]==a[j] && vis[k]==0)
                    {
                        pos=k;
                        break;
                    }
                }
                if(pos)
                {
                    for(int k=pos; k<j; ++k)
                    {
                        vis[k]=1;
                    }
                }
            }
            for(int j=i; j<=n; ++j)
            {
                if(!vis[j]) cnt1[a[j]]=1;
            }
            for(int j=1; j<=m; ++j) cnt[j]+=cnt1[j];
        }
        for(int i=1; i<=m; ++i){
            cout <<cnt[i] <<" ";
        }
    }
    return 0;
}

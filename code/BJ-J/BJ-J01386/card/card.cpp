#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
const int N =5e5+5;
int n,m;
int a[N];
int ans[N],vis[N];
int lst[N],nxt[N],cnt[N];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    rep(i,1,n) cin>>a[i],cnt[a[i]]++;
    rep(i,1,n){
        lst[a[i]]=i;
    }
    rep(i,1,n){
        if(lst[a[i-1]]==i-1){
            cnt[a[i]]+=cnt[a[i-1]];
        }
    }
    rep(i,1,m) cout<<cnt[i]<<' ';
    return 0;
}


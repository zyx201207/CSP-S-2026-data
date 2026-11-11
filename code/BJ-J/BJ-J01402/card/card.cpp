#include<bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
using namespace std;
const int N = 5e5+5;
const int M = 3e5+5;
int a[N],last[N];
int curm[M],nxt[M],ans[M],ch[M];
pair<int,int> cds[M];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m; cin>>n>>m;
    for(int i = 1;i<=n;i++) cin>>a[i];
    for(int i = 1;i<=n;i++) last[i] = curm[a[i]],nxt[a[i]] = i,curm[a[i]] = i;
    for(int i = 1;i<=m;i++) cds[i] = {nxt[i],i};
    for(int i = 1;i<=n;i++) ch[a[i]]++;
    sort(cds+1,cds+m+1);
    for(int i = 1;i<=m;i++)
    {
        int t = cds[i].se;
        int tk = t;
        ans[t] = ch[t];
        t = nxt[t]+1;
        if(t <= n) ch[a[t]] += ch[tk];
    }
    for(int i = 1;i<=m;i++) cout<<ans[i]<<' ';
    return 0;
}

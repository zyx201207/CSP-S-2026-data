#include<bits/stdc++.h>
#define endl '\n'
#define pb push_back

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int N=5e5+233;
int n,m,a[N];
int lst[N],cnt[N],sz[N];
vector<int> t[N];
inline void dfs(int u)
{
    sz[u]=cnt[u];
    for (int i=0;i<t[u].size();i++)
    {
        int v=t[u][i];
        dfs(v),sz[u]+=sz[v];
    }
}

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=n;i>=1;i--)
        if (!lst[a[i]]) lst[a[i]]=i;
    for (int i=1;i<=n;i++) cnt[a[i]]++;
    for (int i=1;i<=m;i++) t[a[lst[i]+1]].push_back(i);
    dfs(a[n]);
    for (int i=1;i<=m;i++) cout<<sz[i]<<' ';
    cout<<endl;

    return 0;
}


#include<bits/stdc++.h>
using namespace std;
int n, m, a[500005], lst[500005];
long long cnt[500005];
vector<int>v[500005];
void dfs(int u){
    for(int x:v[u]) dfs(x), cnt[u] += cnt[x];
    return;
}
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 1;i <= n;i++){
        scanf("%d", &a[i]);
        cnt[a[i]]++;lst[a[i]] = i;
    }
    for(int i = 1;i <= n;i++)
        if(lst[i] < n)
            v[a[lst[i] + 1]].push_back(i);
    dfs(a[n]);
    for(int i = 1;i <= m;i++) printf("%lld ", cnt[i]);
    return 0;
}

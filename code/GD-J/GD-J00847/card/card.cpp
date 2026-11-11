#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+5;
int n,m,a[maxn],mx[maxn],fa[maxn],add[maxn],cnt[maxn],tmp[maxn];
map<int,int>mp;
void dfs(int id,int val){
    if(!id)return;
    if(a[id]==val)dfs(fa[id],val);
    else mx[a[id]]++,dfs(fa[id],a[id]);
}
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=n;i>=1;i--){
        add[i]=a[i];
        cnt[i]++;
        if(mp[a[i]])fa[i]=mp[a[i]];
        else fa[i]=i+1;
        mp[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        dfs(i,a[i]);
        mx[add[i]]++;
    }
    for(int i=1;i<=m;i++)cout<<mx[i]<<' ';
    return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,m,a[N];
int p[M],nxt[N];
int mul[N];
int ans[M];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mul[i]=1;
    }

    for(int i=1;i<=m;i++) p[i]=n+1;
    for(int i=n;i>=1;i--){
        if(p[a[i]]==n+1) p[a[i]]=i;
        nxt[i]=p[a[i]];
    }

    for(int i=1;i<=n;i++){
        if(nxt[i]==n+1) mul[i+1]+=mul[i];
        else mul[nxt[i]+1]+=mul[i];
    }

    for(int u=1;u<=n;u++) ans[a[u]]+=mul[u];

    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
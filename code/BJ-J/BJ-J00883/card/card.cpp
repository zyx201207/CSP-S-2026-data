#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[500005];
int b[300005];
int cnt[500005];
int c[300005];
int fa[500005];

int fd(int x){
    if(fa[x]==x) return x;
    return fa[x]=fd(fa[x]);
}
int main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        fa[i]=i;
        cnt[i]=1;
    }
    for(int i=n;i>=1;i--){
        if(b[a[i]]==0){
            b[a[i]]=i;
        }else{
            int x=fd(b[a[i]]);
            fa[i]=x;
            b[a[i]]=i;
        }
    }
    for(int i=1;i<=n;i++){
        cnt[i]+=cnt[i-1];
        int x=fd(i);
        if(x!=i){
            cnt[x]+=cnt[i];
            cnt[i]=0;
        }
    }
    for(int i=1;i<=n;i++){
    //    cout<<cnt[i]<<"\n";
        c[a[i]]+=cnt[i];
    }
    for(int i=1;i<=m;i++){
        cout<<c[i]<<" ";
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

long long n,m,a[200005],b[200005];
long long maxn=-1e9;

void dfs(int x){
    if(x>m){
        long long cnt=a[b[1]];
        for(int i=2;i<=m;i++){
            cnt=cnt&a[b[i]];
        }
        maxn=max(maxn,cnt);
        return;
    }
    for(int i=b[x-1]+1;i<=n;i++){
        b[x]=i;
        dfs(x+1);
    }
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    long long ans=-1e9;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ans=max(ans,a[i]);
    }
    if(n<=2000){
        dfs(1);
        cout<<maxn;
        return 0;
    }
    cout<<ans;
    return 0;
}

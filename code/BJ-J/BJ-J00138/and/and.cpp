#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N=2e5+5;
int n,a[N],m,ans=-1;

int dfs(int an,int big,int ii){
    if(an==0)return big;
    int bigg=-1;
    for(int i=ii+1;i<=n-an+1;i++){
        int pp=big&a[i];
        bigg=max(bigg,dfs(an-1,pp,i));
    }
    return bigg;
}

signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n-m+1;i++){
        ans=max(ans,dfs(m-1,a[i],i));
    }
    cout<<ans;
}

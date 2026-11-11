#include<bits/stdc++.h>
#define int long long
using namespace std;

constexpr int N=2*1e5+5;
int n,m,a[N],ans;
bitset<N> b;

void dfs(int k,int s){
    if(k==m){
        ans=max(ans,s);
        return;
    }
    for(int i=1;i<=n;i++){
        if(!b[i]){
            b[i]=true;
            dfs(k+1,s&a[i]);
            b[i]=false;
        }
    }

}

signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];

    if(m==n){
        ans=a[1];
        for(int i=2;i<=n;i++)
            ans&=a[i];
        cout<<ans;
        return 0;
    }

    dfs(0,(2<<30)-1);
    cout<<ans;

    return 0;
}

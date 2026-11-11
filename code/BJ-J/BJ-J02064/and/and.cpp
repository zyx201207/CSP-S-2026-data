#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
int a[N];
bool vis[N];
int ans;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int k=29;k>=0;k--){
        int ok=0;
        for(int i=1;i<=n;i++){
            if(vis[i])
                continue;
            if(a[i]&(1<<k))
                ok++;
        }
        if(ok>=m){
            ans+=(1<<k);
            for(int i=1;i<=n;i++){
                if(!vis[i] && !(a[i]&(1<<k))){
                    vis[i]=true;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}

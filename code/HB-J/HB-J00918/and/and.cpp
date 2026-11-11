#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,a[200005],m,ans=-1;
bool v[200005];
void dfs(ll x,ll sum){
    if(x==m){
        ans=max(ans,sum);
        return ;
    }
    for(int i=0;i<n;i++){
        if(!v[i]){
            v[i]=1;
            dfs(x+1,sum&a[i]);
            v[i]=0;
        }

    }

}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        v[i]=1;
        dfs(1,a[i]);
        v[i]=0;
    }
    cout<<ans;
    return 0;
}

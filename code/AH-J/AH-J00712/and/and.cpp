#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
bool vis[N];
ll n,m,a[N],maxn=LLONG_MIN,max1=LLONG_MIN;
void fun(ll cur,ll sum){
    if(sum<maxn) return ;
    if(cur==m){
        maxn=max(sum,maxn); return ;
    }
    for(ll i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            fun(cur+1,(sum&a[i]));
            vis[i]=0;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++) cin>>a[i];
    for(ll i=1;i<=n;i++){
        maxn=LLONG_MIN;
        vis[i]=1;
        fun(1,a[i]);
        vis[i]=0;
        max1=max(max1,maxn);
    }
    cout<<max1;
    return 0;
}

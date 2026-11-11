#include<bits/stdc++.h>
#define ll long long
#define pii pair<int ,int >
#define pll pair<long long, long long >

using namespace std;
const int N=5e5+5,W=1e9,mod=998244353;
ll n,m,arr[N],pre[N],ans;

void sol(){
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>arr[i];
    }
    sort(arr+1,arr+n+1);
    for(int i=1;i<=n;++i){
        pre[i]=arr[i]+pre[i-1];
        ll l=1,r=i,res=i;
        while(l<=r){
            int mid=l+r>>1;
            if((i-mid+1)*arr[i]-(pre[i]-pre[mid-1])<=m){
                r=mid-1;
                res=mid;
            }
            else{
                l=mid+1;

            }
        }
        ans=max(ans,i-res+1);
    }
    cout<<ans;
    
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int t=1;
    int c=0;
    //cin>>t;
    while(t--){
        sol();
    } 
    return 0;
}
/*
author:_aa_

*/
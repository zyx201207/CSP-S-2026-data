#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int N=5e5+5;
int a[N]={};
bool check(int x){
    int sum=0;
    for(int i=1;i<=n;i++){
        if(a[i]<x){
            sum+=x-a[i];
        }
    }
    return sum<=m;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    int l=1,r;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        r=max(r,a[i]);
    }
    while(l<r){
        int mid=(l+r+1)>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(a[i]<=l) ans++;
    }
    cout<<ans<<'\n';
    return 0;
}

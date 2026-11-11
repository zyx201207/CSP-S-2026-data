#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll maxa[200005];
bool cmp(ll a,ll b){
    return a>b;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ll n,m,ans;
    cin>>n>>m;
    ll a[n+1];
    for(ll i=0;i<n;i++){
        cin>>a[i];
        maxa[m-1]=max(maxa[m-1],a[i]);
        sort(maxa,maxa+m,cmp);
    }
    if(m==1){
        cout<<maxa[0];
        return 0;
    }else if(m==n){
        for(int i=0;i<n-1;i++){
            ans=a[i]&a[i+1];
        }
        cout<<ans;
        return 0;
    }
    for(ll i=1;i<m;i++){
        ans=maxa[i-1]&maxa[i];
    }
    cout<<ans;
    return 0;
}
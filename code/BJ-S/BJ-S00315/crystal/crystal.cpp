#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
int n;
ll m;
ll a[N];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    ll c=0;
    int l=1;
    ll ans=-1;
    for(int r=1;r<=n;r++){
        c+=(r-l)*(a[r]-a[r-1]);
        if(c>m){
            ans=max(ans,(ll)(r-l));
            while(c>m){
                c-=a[r]-a[l];
                l++;
            }
        }
    }
    cout<<(ans==-1?n:ans);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+10;
int n;
ll m;
ll a[N];
ll t[N];
ll s=0;
int ans=0;
bool cmp(ll x,ll y){
    return x<y;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) t[i]=1;
    sort(a+1,a+1+n,cmp);
    for(int l=1,r=1;l<=n&&r<=n;){
        ll o=(abs(a[r]-a[r-1]))*t[r-1];
        if((s+o)<=m){
            s+=o;
            t[r]+=t[r-1];
            r++;
            ans=max(ans,r-l);

        }
        else{
            t[r-1]--;
            s=s-(abs(a[r-1]-a[l]));
            if(s<0) s=0;
            l++;
        }

    }
    cout<<ans;
    return 0;
}

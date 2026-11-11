#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+20;
ll n;
ll m,j;
ll a[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    j=m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    ll maxn=1;
    ll ans=1,l=1,r=2;
    for(int i=1;i<=n;i++){
        if((a[r]-a[r-1])*(r-l)<=j){
            j-=(a[r]-a[r-1])*(r-l);
            ans++;
            maxn=max(maxn,ans);
            r++;
            continue;
        }
        if(l==r){
            l=r;
            r++;
            j=m;
            ans=1;
            continue;
        }

        j+=a[r]-a[l];
        l++;
        ans--;
    }
    cout<<maxn;
}

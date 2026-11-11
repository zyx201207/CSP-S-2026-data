#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
ll a[N];
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    ll sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        sum+=a[i];
    }
    int l=1,r=n;
    ll lsum=0,rsum=0;
    ll ans=0;
    while(l<r&&lsum<=sum/2&&rsum<=sum/2){
        if(c[l]!=c[r]){
            ans+=min(a[l],a[r]);
        }
        ll num=min(a[l],a[r]);
        lsum+=num;
        rsum+=num;
        a[l]-=num;
        a[r]-=num;
        if(a[l]==0){
            l++;
        }else{
            r--;
        }
    }
    cout<<ans;
    return 0;
}

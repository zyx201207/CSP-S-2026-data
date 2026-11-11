#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,maxn = 0;
ll a[100005],cnt[100005],cf[100005];
bool cmp(ll a,ll b){
    return a<b;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    ll sum = 0;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    ll cost = 0;
    for(int i = 1;i<=n;i++){
        cnt[i] = cnt[i-1]+(a[i]-a[i-1])*(i-1);
        cf[i] = a[i]-a[i-1];
        //cout<<a[i]<<" "<<cnt[i]<<endl;
    }
    cost = cnt[n];
    //cout<<cost<<endl;
    for(int i = 1;i<=n;i++){
        a[i] = a[i-1]+cf[i];
    }
    cost = cost-m;
    if(cost<=0){
        cout<<n;
        return 0;
    }
    int maxn = 0;
    for(int i = n;i>=1;i--){
        int l = 1,r = i-1;
        while(l<r){
            int mid = (r+l)/2;
            ll p = cnt[i]-cnt[mid]-(a[i]-a[mid])*(mid-1);
            //cout<<i<<' '<<l<<" "<<r<<' ';
            if(p>m){
                l = mid+1;
            }else{
                r = mid;
            }
            //cout<<mid<<" "<<p<<endl;
        }
        maxn = max(maxn,i-l+1);
    }
    cout<<maxn;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

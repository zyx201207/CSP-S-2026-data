#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
struct node{
    ll l,r;
    char c;
} a[200005];
ll bins(ll l,ll r,ll x){
    ll ans = 0,mid;
    while(l <= r){
        mid = (l+r)/2;
        if(a[mid].l <= x){
            ans = mid;
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    return ans;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n ;
    ll sum = 0;
    for(int i = 1; i <= n; i++){
        ll x;
        char z;
        cin >> x >> z ;
        a[i].l = a[i-1].r+1;
        a[i].r = a[i].l+x-1;
        a[i].c = z;
        sum += x;
    }
    ll res = 0;
    for(int i = 1; i <= n; i++){
        ll tl = a[i].l;
        ll tr = a[i].r;
        ll nl = sum-tr+1;
        ll nr = sum-tl+1;
        ll pl = bins(1,n,nl);
        ll pr = bins(1,n,nr);
        if(pl == pr && a[pl].c != a[i].c){
            res += nr-nl+1;
            continue;
        }
        if(a[pl].c != a[i].c){
            res += a[pl].r-nl+1;
        }
        if(a[pr].c != a[i].c){
            res += nr-a[pr].l+1;
        }
    }
    if(res % 2){
        res++;
    }
    cout << res/2;
    return 0;
}

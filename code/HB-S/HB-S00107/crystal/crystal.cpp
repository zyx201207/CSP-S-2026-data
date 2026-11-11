#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=5e5+10;
int n;
ll m,a[N],b[N],c[N];
bool ok(int mid,int m){
    ll x;
    //cout<<(mid+1)*a[mid]+m<<' '<<c[mid+1]-(a[n-1]-a[mid])*(n-mid)<<'\n';
    if((mid+1)*a[mid]+m<c[mid+1]-(a[n-1]-a[mid])*(n-mid)){
        return 1;
    }
    return 1;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    sort(a,a+n);
    for(int i=0;i<n;i++){
        b[i]=a[n-1]-a[i];
        c[i+1]=c[i]+b[i];
    }
    //for(int i=0;i<=n;i++){
    //    cout<<b[i]<<' ';
    //}
    //cout<<'\n';
    //for(int i=0;i<=n;i++){
    //    cout<<c[i]<<' ';
    //}
    //cout<<'\n';
    int mid;
    int l=0,r=n;
    while(l<=r){
        mid=l+r>>1;
        //cout<<mid<<" "<<l<<" "<<r<<'\n';
        if(ok(mid,m)){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<mid<<'\n';
    return 0;
}
//my CSP2026 was died
//Can I rebirth?

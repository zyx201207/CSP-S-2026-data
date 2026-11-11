#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
const int N=5e5+5;
int n,m;
ll a[N],sum[N];
bool check(int x){
    rep(i,x,n){
        if((x-1)*a[i]-sum[i-1]+sum[i-x]<=m) return 1;
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    rep(i,1,n) cin>>a[i];
    sort(a+1,a+n+1);
    rep(i,1,n) sum[i]=sum[i-1]+a[i];
    int l=1,r=n;
    while(l<r){
        int mid=(l+r+1)>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    cout<<l;
    return 0;
}
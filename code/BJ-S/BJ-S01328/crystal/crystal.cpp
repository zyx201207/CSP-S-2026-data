#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+11;
int n,m,a[N],d[N],times[N];
bool check(int val){
    for(int l=1;l+val-1<=n;l++){
        int r=l+val-1;
        int need=times[r]-times[l]-l*(a[r]-a[l]);
        if(need<=m)return true;
    }
    return false;
}
int bsearch(int x){
    int l=1,r=n;
    while(l<r){
        int m=(l+r+1)/2;
        if(check(m)){
            l=m;
        }else{
            r=m-1;
        }
    }
    return l;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        d[i]=a[i]-a[i-1];
        times[i]=d[i]*i+times[i-1];
    }
    cout<<bsearch(m);
    return 0;
}
//time():O(nlogn)

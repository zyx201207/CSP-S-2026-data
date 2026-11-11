#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,l,r,mid;
long long m,a[N],sum[N];
inline void file(){freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);}
inline bool chk(int len){
    long long res;
    for(int i(1);i<=n-len+1;++i){
        res=a[i+len-1]*len-(sum[i+len-1]-sum[i-1]);
        if(res<=m) return 1;
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    file();
    cin >> n >> m,l=1,r=n;
    for(int i(1);i<=n;++i) cin >> a[i];
    sort(a+1,a+n+1);
    for(int i(1);i<=n;++i) sum[i]=a[i]+sum[i-1];
    while(l<r){
        mid=l+r+1>>1;
        if(chk(mid)) l=mid;
        else r=mid-1;
    }
    cout << l;
    return 0;
}
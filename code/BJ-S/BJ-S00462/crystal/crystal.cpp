#include <bits/stdc++.h>
using namespace std;
constexpr int N = 5e5+10;
using ull = long long;
ull v[N];
size_t n,m,cnt,i;
struct pii {
    int a;
    ull b;
    pii(int a = 0,ull b = 0)
        :a(a),b(b){}
};
pii finds(ull k){
    ull sum = 0;
    int cnt1 = 0;
    for(int i=1;i<=n;++i){
        if(v[i]>k) continue;
        sum+=k-v[i];
        ++cnt1;
    }
    return {cnt1,sum};
}
int main(){
    //A&B
    freopen("crystal.in","r",stdin);
    //freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n>>m;
    for(i=1;i<=n;++i){
        cin>>v[i];
    }
    sort(v+1,v+n+1);
    ull l = v[0],r = v[n];
    int bestn = -1;
    while(l<r){
        ull mid = (l+r+1)>>1;
        //cout<<mid<<endl;
        pii f = finds(mid);
        if(f.b<=m){
            l = mid;
            bestn = max(bestn,f.a);
            //cout<<l<<" "<<r<<endl;
        }else{
            r = mid-1;
            //cout<<l<<" "<<r<<endl;
        }
    }
    cout<<bestn<<flush;
    return 0;
}

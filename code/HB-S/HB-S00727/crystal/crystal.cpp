#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifdef LOCAL
using namespace std::chrono;
#define runt0 auto _t0=steady_clock::now();
#define seetime cerr<<"RunTime: "<<duration<double,micro>(steady_clock::now()-_t0).count()<<"ms\n"
#else
#define runt0
#define seetime
#endif
const int N=500050,IO=1<<22;
unsigned char buf[IO],*rp1,*rp2;
#define gc() (rp1==rp2&&(rp2=(rp1=buf)+fread(buf,1,IO,stdin))==rp1?EOF:*rp1++)
#define endl putchar('\n')
inline ll rd(){
    ll x=0;int f=1,c=gc();
    while(!isdigit(c)){
        if(c=='-'){f=-1;}
        c=gc();
    }
    while(isdigit(c)){
        x=x*10+(c^48);
        c=gc();
    }
    return x*f;
}
inline void wt(int x){
    if(x>9){
        wt(x/10);
    }
    putchar((x%10)^48);
    return;
}
int n;
ll m,a[N],sum[N],ans;
bool check(ll k){
    for(int i=k;i<=n;i++){
        if(a[i]*k-sum[i]+sum[i-k]<=m){
            return 1;
        }
    }
    return 0;
}
int main(){//ok
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    runt0;
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);//duoceqingkong!
    n=rd(),m=rd();
    for(int i=1;i<=n;i++){
        a[i]=rd();
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    //bound
    ll l=1,r=n;
    while(l<=r){//O(log(n))
        ll mid=(l+r)>>1;
        if(check(mid)){//O(n)
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    wt(ans);
    endl;
    seetime;
    return 0;
}
/*
g++ "/home/user/Desktop/HB-S00727/crystal.cpp" -o T1 -O2 -std=c++14 -static -Wall -Wextra -Wshadow -DLOCAL
*/
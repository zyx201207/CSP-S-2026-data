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
const int N=300050,IO=1<<20;
unsigned char buf[IO],*rp1,*rp2;
#define gc() (rp1==rp2&&(rp2=(rp1=buf)+fread(buf,1,IO,stdin))==rp1?EOF:*rp1++)
inline int rd(){
    int x=0,c=gc();
    while(!isdigit(c)){
        c=gc();
    }
    while(isdigit(c)){
        x=x*10+(c^48);
        c=gc();
    }
    return x;
}
inline void wt(int x){
    if(x>9){
        wt(x/10);
    }
    putchar((x%10)^48);
    return;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);//duoceqingkong!
    int c,T;cin>>c>>T;
    while(T--){
        int n,d;cin>>n>>d;
        for(int i=1,x;i<=n;i++){
            cin>>x;
        }
        cout<<(n*n-n)/3<<'\n';
    }
    return 0;
}
/*
g++ "/home/user/test1.cpp" -o T1 -O2 -std=c++14 -static -Wall -Wextra -Wshadow -DLOCAL
*/
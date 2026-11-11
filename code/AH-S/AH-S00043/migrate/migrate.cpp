/*

cd ~/draft && ulimit -s 1048576 && g++ migrate.cpp -std=c++14 -O2 -Wall -fsanitize=address,leak,undefined -o migrate && ./migrate

*/
#include <bits/stdc++.h>
using namespace std;
#define upp(x,y,z) for(x=(y);x<=(z);x++)
#define low(x,y,z) for(x=(y);x>=(z);x--)
#define fs(x) fixed<<setprecision(x)
#define pb push_back
#define fi first
#define se second
#define ll long long
#define line '\n'
const int ext=0xf; const int N=2e6+ext; const int mod=998244353; const ll inf=0x3fffffffffffffff;
template<typename t0> void ckmax(t0 &x,t0 y){if(x<y){x=y;} }
template<typename t0> void ckmin(t0 &x,t0 y){if(x>y){x=y;} }
void code(); void io(); void perf(); int main(){io(); code(); perf(); return 0;}
bool mb;
int c,t,n,l,r,lc,rc; ll c1,c2,d,ans,a[N],lcnt[N],rcnt[N];
void code(){
    int i,j; cin>>c>>t; while(t--){
        cin>>n>>d; upp(i,1,n){cin>>a[i];} ans=0;
        upp(i,1,n-1){
            lcnt[i]=1;
            l=lower_bound(a+1,a+1+n,a[i]-d)-a;
            r=lower_bound(a+1,a+1+n,a[i+1]-d)-a;
            if((l<r)&&(l>=1)){lcnt[i]+=lcnt[l]+r-l-1;}
        }
        low(i,n,2){
            rcnt[i]=1;
            l=upper_bound(a+1,a+1+n,a[i]+d)-a-1;
            r=upper_bound(a+1,a+1+n,a[i-1]+d)-a-1;
            if((r<l)&&(l<=n)){rcnt[i]+=rcnt[l]+l-r-1;}
        }
        upp(i,1,n-2){
            l=upper_bound(a+1,a+1+n,a[i]+d)-a-1;
            if(i+2>l){continue;}
            lc=lower_bound(a+1,a+1+n,a[l-1]-d)-a;
            rc=upper_bound(a+1,a+1+n,a[l]+d)-a-1;
            r=upper_bound(a+1,a+1+n,a[l-1]+d)-a-1;
            l=upper_bound(a+1,a+1+n,a[l-2]+d)-a-1;
            if(l<r){
                c1=lcnt[i]; c2=r-l-1+rcnt[r];
                if(lc<i){c1=1;} if(rc>r){c2=1;}
                ans+=c1*c2;
            }
        }
        cout<<ans<<line;
    }
}
bool me;
void io(){
    freopen("migrate.in","r",stdin); freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
}
void perf(){
    // cerr<<"Time used:"<<fs(3)<<1.0*clock()/CLOCKS_PER_SEC<<"s."<<endl;
    // cerr<<"Memory used:"<<fs(3)<<abs(1.0*(&me-&mb)/1024.0/1024.0)<<"MB."<<endl;
}
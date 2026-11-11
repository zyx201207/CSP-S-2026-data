/*

cd ~/draft && ulimit -s 1048576 && g++ crystal.cpp -std=c++14 -O2 -Wall -fsanitize=address,leak,undefined -o crystal && ./crystal

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
const int ext=0xf; const int N=1e6+ext; const int mod=998244353; const int inf=0x3fffffff;
template<typename t0> void ckmax(t0 &x,t0 y){if(x<y){x=y;} }
template<typename t0> void ckmin(t0 &x,t0 y){if(x>y){x=y;} }
void code(); void io(); void perf(); int main(){io(); code(); perf(); return 0;}
bool mb;
int n,ans,l,r,mid; ll m,now,a[N],s[N];
void code(){
    int i,j; cin>>n>>m; upp(i,1,n){cin>>a[i];}
    sort(a+1,a+1+n);
    upp(i,1,n){s[i]=s[i-1]+a[i];} ans=1;
    upp(i,2,n){
        l=1; r=i-1; while(l<r){
            mid=l+r>>1; now=a[i]*(i-mid+1)-s[i]+s[mid-1];
            if(now<=m){r=mid-1;} else{l=mid+1;}
        }
        ckmax(ans,i-l+1);
    }
    cout<<ans<<line;
}
bool me;
void io(){
    freopen("crystal.in","r",stdin); freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
}
void perf(){
    // cerr<<"Time used:"<<fs(3)<<1.0*clock()/CLOCKS_PER_SEC<<"s."<<endl;
    // cerr<<"Memory used:"<<fs(3)<<abs(1.0*(&me-&mb)/1024.0/1024.0)<<"MB."<<endl;
}
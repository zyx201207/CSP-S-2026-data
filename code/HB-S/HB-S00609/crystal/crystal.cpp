#include<bits/stdc++.h>
using namespace std;

#define REP(a,b,c) for(int a = (b);(a) <= (c);++a)
#define DOW(a,b,c) for(int a = (b);(a) >= (c);--a)
#define pr printf
#define sc scanf
#define Sz(v) (int(v.size()))
#define FALL(v) v.begin(),v.end()

typedef long long ll;

const int MAXN = 1e5+10;
const int MOD = 0;

/*
g++ -O2 -std=c++14 crystal.cpp -o crystal.exe
./crystal.exe
*/

int bf(int p,ll m,ll ap,const vector<ll>& ps){
    int l = 0,r = p,ret = -1;
    while(l <= r){
        int mid = (l+r)/2,len = p-mid+1;
        if(ap*(ll)len-(ps[p]-(mid == 0 ? 0 : ps[mid-1])) <= m) r = mid-1,ret = max(ret,len);
        else l = mid+1;

        // pr("mid = %d , len = %d ,da = %lld\n",mid,len,ap*len-(ps[p]-ps[mid-1]));
    }

// pr("\n\n up is p = %d ap = %d ret = %d \n>>>>>>\n",p,ap,ret);

    return ret;
}

int main(){

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    int n; ll m;
    sc("%d%lld",&n,&m);
    vector<ll> a(n),ps(n,0);
    REP(i,0,n-1) sc("%lld",&a[i]);
    sort(FALL(a));
    ps[0] = a[0];
    REP(i,1,n-1) ps[i] = ps[i-1]+a[i];
    int ans = 1;
    REP(i,0,n-1) ans = max(ans,bf(i,m,a[i],ps));
    pr("%d",ans);


    return 0;
}
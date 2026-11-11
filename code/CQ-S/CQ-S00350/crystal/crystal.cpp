#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
#define int long long
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define rep1(i,x,y) for(int i=x;i>=y;i--)
#define pb push_back
void in(int &x) {
    x=false;
    char c=getchar();
    int f=1;
    while(c>'9'||c<'0') {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9') {
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    x*=f;
}
int T=1;
const int N=5e5+10;
int n,m;
int a[N];
void solve() {
    in(n),in(m);
    rep(i,1,n) in(a[i]);
    sort(a+1,a+1+n);
    int l=1,res=1;
    int ct=0,ss=0;
    rep(i,1,n) {
        ct++;
        ss+=a[i];
        while(l<=i&&ct*a[i]-ss>m) {
            ct--;
            ss-=a[l];
            l++;
        }
        res=max(res,i-l+1);
    }
    printf("%lld\n",res);
}
signed main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    while(T--) {
        solve();
    }
    return false;
}
/*
g++ crystal.cpp -o c -std=c++14 -O2 "-Wl,--stack=10000000000" -Wall
*/
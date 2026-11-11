#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=5e5+11;
long long a[N],b[N];
long long s[10000009];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    cin>>n>>m;
    rep(i,1,n)cin>>a[i];
    sort(a+1,a+1+n);
    rep(i,1,n){
        s[i]=a[i]+s[i-1];
    }
    rep(i,1,n){
        b[i]=a[i]*i-s[i];
    }
    int res=0;
    rep(i,1,n){
        if(m>=b[i]) res=i;
        else break;
    }
    cout<<res;
    return 0;
}

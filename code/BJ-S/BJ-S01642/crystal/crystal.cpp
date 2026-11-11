#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+10;
int n,m;
int a[N];
bool check(int x,int q){
    int cnt=0;
    for (int i=q;i<x;i++){
        if (a[x]==a[i]) break;
        cnt+=a[x]-a[i];
    }
    if (cnt>m) return false;
    else return true;
}
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while (c>'9' or c<'0'){
        if (c=='-'){
            f=-1;
            c=getchar();
        }
    }
    while (c<='9' and c>='0'){
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}
int ans;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read();
    m=read();
    for (int i=1;i<=n;i++) a[i]=read();
    sort (a+1,a+1+n);
    a[n+1]=-1000000000001;
    for (int i=1;i<=n;i++){
        if (a[i]==a[i+1]) continue;
        int l=i,r=n;
        while (l<r){
            int mid=(l+r+1)>>1;
            if (check(mid,i)==true) l=mid;
            else r=mid-1;
        }
        ans=max(r-i+1,ans);
    }
    cout << ans;
    // if (check(315275)==true) cout << "woshizhizhang";
    // for (int i=1;i<=n;i++) cout << a[i] << endl;
    return 0;
}
/*
Oct31==Dec25?
1+x=y;
315275+x=315829
*/
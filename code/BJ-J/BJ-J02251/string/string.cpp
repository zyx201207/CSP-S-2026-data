#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N=2e5+5;
ll n, cur, a[N], len, ans;
char c[N];

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin>>n;
    ll u; char v;
    for(int i=1;i<=n;i++){
        cin>>u>>v;
        len+=u;
        if(v!=c[cur]){
            cur++;
            a[cur]=u+a[cur-1];
            c[cur]=v;
        }else
            a[cur]+=u;
    }
    ll l=1, r=cur, x=0, p;
    while(l<r){
        p=min(a[l]-x, len-x-a[r-1]);
        if(c[l]!=c[r]) ans+=p;
        x+=p;
        if(x==a[l]) l++;
        if(len-x==a[r-1]) r--;
    }
    cout<<ans<<endl;
    return 0;
}
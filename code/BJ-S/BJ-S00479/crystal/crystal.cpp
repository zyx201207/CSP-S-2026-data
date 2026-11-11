#include <bits/stdc++.h>
using namespace std;
long long a[500005],n,m,pos,ans=1;
bool cmp(long long a,long long b){
    return a>b;
}
void f(){
    pos--;
    for(long long i=pos+1;i<n;i++) a[i]=a[i+1];
    ans++;
    n--;
    if(pos==1) {ans++;return;}
    if(a[pos]==a[pos-1]) f();
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    long long x=n;
    for(long long i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1,cmp);
    while(m>0){
        long long d=a[n-1]-a[n];
        if(m<d) break;
        m-=d;
        n--;
        ans++;
        pos=n;
        while(a[pos]>a[pos-1]) {swap(a[pos],a[pos-1]);pos--;}
        while(a[pos]==a[pos-1]) f();
    }
    if(ans>x) {cout<<x;return 0;}
    cout<<ans;
    return 0;
}

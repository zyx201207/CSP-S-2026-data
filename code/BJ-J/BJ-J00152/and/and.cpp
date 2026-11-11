#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int a[N],b[N];
bool cmp(int a,int b) {
    return a>b;
}
int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    ll ans=0;
    for(int i=1;i<=m;i++) {
        b[i]=a[i];
    }
    for(int i=2;i<=m;i++) {
        b[i]&=b[i-1];
    }
    ans=b[m];
    cout<<ans;
    return 0;
}

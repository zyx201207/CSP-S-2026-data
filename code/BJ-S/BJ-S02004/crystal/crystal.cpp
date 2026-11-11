#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500010];
int b[500010];
int n,m;
bool check(int mid){
    for (int i=mid; i<=n; i++){
        int tmp=a[i]*mid-(b[i]-b[i-mid]);
        if (tmp<=m) return 1;
    }
    return 0;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1; i<=n; i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for (int i=1; i<=n; i++){
        b[i]=a[i]+b[i-1];
    }
    int l=1,r=n;
    while (l<r){
        int mid=(l+r+1>>1);
        if (check(mid)) l=mid;
        else r=mid-1;
    }
    cout<<l;
}

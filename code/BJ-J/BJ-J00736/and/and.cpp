#include<bits/stdc++.h>
#define int long long
using namespace std;
int f[200005][30];
int a[200005];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1,greater<int>());
    cout<<a[m];
    return 0;
}

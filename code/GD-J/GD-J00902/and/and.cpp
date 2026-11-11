#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2E5+10;
int a[N],n,m;
bool cmp(int x,int y){
    return x>y;
}void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1,cmp);
    cout<<a[m];
}signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    solve();
}


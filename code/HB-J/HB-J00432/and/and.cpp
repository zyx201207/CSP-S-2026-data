#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt;
long long a[200005];
void solve(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    cnt=a[n-1];
    for(int i=n-1;i>n-1-m;i--){
        cnt&=a[i];
    }
    cout<<cnt;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    solve();
    return 0;
}

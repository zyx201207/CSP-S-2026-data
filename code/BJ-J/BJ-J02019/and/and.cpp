#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    ans=a[n];
    for(int i=n;i>n-m;i--){
        ans&=a[i];
    }
    cout<<ans<<'\n';
    return 0;
}

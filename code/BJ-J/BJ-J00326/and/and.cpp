#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10000010],ans=-9999999,cnt=0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        ans=max(ans,a[i]);
    }
    cout<<ans;
    return 0;
}

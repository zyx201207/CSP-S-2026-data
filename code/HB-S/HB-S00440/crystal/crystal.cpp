#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans=0;
int main(){
    ios::sync_with_stdio();
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int mid=a[n/2+1];
    for(int i=1;i<=n;i++){
        m-=(mid-a[i]);
        if(a[i]>mid) break;
        ans++;
    }
    cout<<ans;
    return 0;
}

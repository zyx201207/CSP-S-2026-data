#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int ans=a[n];
    for(int i=n-1;i>=n-m+1;i--){
        ans&=a[i];
    }
    cout<<ans;
    return 0;
}

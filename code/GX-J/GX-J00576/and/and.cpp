#include<bits/stdc++.h>
using namespace std;

long long a[200005],m,n,ans=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=n+1;j<=n;j++){
            ans=max(ans,a[i]&a[j]);
        }
    }
    cout<<ans;

    return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,a[100000010],k[100000010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    for(long long i=1;i<=n;i++){
        for(long long j=i+1;j<=n;j++){
            ans=max(ans,a[i]&a[j]);
        }
    }
    cout<<ans;
    return 0;
}

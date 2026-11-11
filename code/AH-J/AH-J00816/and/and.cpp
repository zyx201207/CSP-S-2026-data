#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],f[200010],maxn=0,ans,x;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    x=n;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    for(long long i=1;i<=n;i++){
        for(long long j=i+1;j<=n;j++){
            ans=a[i]&a[j];
            maxn=max(maxn,ans);
        }
    }
    cout<<maxn;
    return 0;
}

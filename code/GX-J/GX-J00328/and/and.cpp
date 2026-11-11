#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
int main(){
    freopen("and.int","r",stdin);
    freopen("and.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long  n,m,x;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    long long maxn=-1e9;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            maxn=max(a[i]&a[j],maxn);
        }
    }
    cout<<maxn;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,a[200007],v[200007];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int m;
    cin>>n>>m;
    m=min(n,n-m);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int maxn=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            maxn=max(a[i]&a[j],maxn);
        }
    }
    cout<<maxn;
    return 0;
}

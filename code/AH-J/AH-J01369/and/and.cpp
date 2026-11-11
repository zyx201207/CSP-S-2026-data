#include<bits/stdc++.h>
using namespace std;
int a[19991];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    int maxn=0;
    int i,j;
    cin>>n>>m;
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    for(i=1;i<=n;i++){
        for(j=i;j<=n;j++){
            maxn=max(maxn,a[i]&a[j]);
        }
    }
    cout<<maxn;

    return 0;
}

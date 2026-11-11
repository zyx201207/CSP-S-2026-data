#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m;
int a[N],lf[M],ans[M];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        lf[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            j=lf[a[j]];
            ans[a[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500010];
signed main(){
    freopen ("card.in","r",stdin);
    freopen ("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        if(a[i]!=a[i+1]){
            cout<<i<<" ";
        }
    }
    cout<<n;
    return 0;
}

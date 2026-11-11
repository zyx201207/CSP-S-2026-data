#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005],b[300005],n,m;
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j;k<=n;k++){
                b[a[k]]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]+1<<" ";
    }
    return 0;
}

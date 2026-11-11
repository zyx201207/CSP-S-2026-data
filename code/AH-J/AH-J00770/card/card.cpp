#include<bits/stdc++.h>
using namespace std;
int cnt[500050];
int a[500050];
int n,m;
int i,j;
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    for(i=1;i<=m;i++){
        cout<<n<<" ";
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N=2e5+7;

int T,n,m;
int a[N];
int ans[N],pre[31000];
signed main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        pre[a[i]]=i;
    }
    for(int i=1;i<=n;i++) {
        for(int j=pre[a[i]];j<=n;j++) {
            ans[a[j]]+=1;
        }
    }
    for(int i=1;i<=m;i++) {
        cout<<ans[i]<<' ';
    }
    return 0;
}

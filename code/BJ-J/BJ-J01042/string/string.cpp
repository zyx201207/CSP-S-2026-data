#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node {
    int num;
    char c;
};
node a[200005];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,ans=0;cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i].num>>a[i].c;
    }
    for(int i=1;i<=n/2;++i){
        if(a[n-i+1].c!=a[i].c){
            ans+=min(a[n-i-1].num,a[i].num);
        }
    }
    cout<<ans;
    return 0;
}

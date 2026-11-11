#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100005];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    cout<<n<<" "<<m<<" "<<m;
    return 0;
}

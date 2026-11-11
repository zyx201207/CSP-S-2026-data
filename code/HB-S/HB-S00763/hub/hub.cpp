#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+7;

int n,m,ans;
int a[N],sum[N];

signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<ans<<"\n";
    return 0;
}
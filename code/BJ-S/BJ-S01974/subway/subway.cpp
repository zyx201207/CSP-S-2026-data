#include <bits/stdc++.h>
using namespace std;
const int N=5e5+1;
int n,m,c,d,q;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    int w[m+1];
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    int a[m+1];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int x;
            cin>>x;
            int t;
            cin>>t;
            a[x]+=t;
        }
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        long long ans=0;
        ans+=w[l];
        ans+=w[r];
        ans+=a[l];
        ans+=a[r];
        cout<<ans<<"\n";
    }
    return 0;
}
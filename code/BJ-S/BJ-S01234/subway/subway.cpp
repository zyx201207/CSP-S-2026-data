#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,c,d,q;
int w[100000],t[100000];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int i=1;i<=2*k;i++){
            int op,tt;
            cin>>op>>tt;
            t[op]=tt;
        }
    }
    for(int i=1;i<=q;i++){
        int l,r;
        cin>>l>>r;
        cout<<w[l]+w[r]+t[l]+t[r]<<endl;
    }
    return 0;
}

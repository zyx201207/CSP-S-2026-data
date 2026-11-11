#include "bits/stdc++.h"
#define int long long
using namespace std;
const int M=5e5+10,N=300;
int c,n,m,d,q;
int w[M];
int t[N][M];
bool a_[N][M];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int aa,tt;
            cin>>aa>>tt;
            a_[i][aa]=1;
            t[i][aa]=tt;
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        int sum=w[x]+w[y];
        bool fl=0,r;
        for(int i=1;i<=n;i++){
            if(a_[i][x] && a_[i][y]){
                fl=1;
                r=i;
                break;
            }
        }
        if(fl==1){
            sum+=t[r][x]+t[r][y];
            cout<<sum<<"\n";
        }else{
            cout<<sum<<"\n";
        }
    }
    return 0;
}

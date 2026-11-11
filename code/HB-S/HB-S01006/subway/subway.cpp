#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int c,n,m,d,q;
const int N=5e5+7;
int w[N];
int a[505][N],t[505][N];
int ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("subway.in","r",stdin);
    //freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    int l,r;
    while(q--){
        ans=0;
        cin>>l>>r;
        ans+=(w[l]+w[r]);
        /*for(int i=1;i<=n;i++){
            if(a[i][1]==l&&a[i][2]==r||a[i][1]==r&&a[i][2]==l){
                cout<<ans<<endl;
                break;
            }
        }*/
        cout<<ans<<endl;
    }
    return 0;
}

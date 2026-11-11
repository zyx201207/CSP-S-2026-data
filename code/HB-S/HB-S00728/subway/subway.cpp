#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
int a[N];
int f[N][N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    int k;
    for(int i=1;i<=2;i++){
        cin>>k;
        for(int j=1;j<=k*2;j++){
            cin>>f[i][j];
        }
    }
    int l,r;
    int ans=1e9;
    for(int i=1;i<=q;i++){
        cin>>l>>r;
        ans=min(f[l-1][r-1],ans);
        cout<<ans;
    }

    return 0;
}

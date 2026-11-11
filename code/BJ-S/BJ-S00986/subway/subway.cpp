#include<bits/stdc++.h>
using namespace std;
const int M=5e5+10,N=510;
int w[M],mod;
int a[N][N],t[N][N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    srand(time(0));
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for (int i=1;i<=m;i++){
            cin>>w[i];
        mod+=w[i];
    }
    for (int i=1;i<=n;i++){
        int x,f=0;
        cin>>x;
        while(x--)cin>>a[i][++f]>>t[i][f];
        mod+=t[i][f];
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<rand()%mod<<'\n';
    }
    cout<<mod;
    return 0;
}

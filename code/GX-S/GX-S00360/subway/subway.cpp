#include<bits/stdc++.h>
using namespace std;
int w[10000];
int a[10000];
int t[10000];
int x[10000];
int y[10000];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q,k;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int j=1;j<=n;j++){
       cin>>k;
       for(int e=1;e<=k;e++){
        cin>>a[e]>>t[e];
       }
    }

    for(int p=1;p<=q;p++){
        cin>>x[p]>>y[p];
    }
    return 0;
}

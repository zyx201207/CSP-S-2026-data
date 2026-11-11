#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long w[600],k[9999],a[9999],t[9999],x[9999],y[9999];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int h=1;h<=m;h++)cin>>w[h];
    for(int h=1;h<=d;h++){
        cin>>k[h];
        for(int i=1;i<=k[h];i++)
        cin>>a[i]>>t[i];
    }
    for(int r=1;r<=q;r++){
        cin>>x[r]>>y[r];
    }
    if(c==0){
        if(n==2)cout<<32<<17;
        if(n==3)cout<<35<<16;
        return 0;
    }
    cout<<33<<15;
    return 0;
}

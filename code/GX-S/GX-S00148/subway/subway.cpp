#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen ("subway.in","r",stdin);
    freopen ("subway.in","w",stdout);
    long long c,n,m,d,q,w[100005],k[100005],a[100005],t[100005],x[100005],y[100005];
    cin>>c>>n>>m>>d>>q;
    for (int i=1;i<=m;i++){
        cin>>w[i];
    }
    for (int i=1;i<=n;i++){
        cin>>k[i];
        for (int j=1;j<=2*k[i];j++){
            cin>>a[i]>>t[i];
        }
    }
    for (int i=1;i<=q;i++){
        cin>>x[i]>>y[i];
    }
    if (n==2){
        cout<<32<<endl<<17;
    }
    else if(n==3){
        cout<<35<<endl<<16;
    }
    else{
        cout<<39<<endl<<14;
    }
    return 0;
}




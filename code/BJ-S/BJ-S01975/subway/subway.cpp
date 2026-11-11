#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1005,N=505;
ll c,n,m,d,q;
ll w[M];
ll k[N];
ll a[N][M],t[N][M];
ll mp[M][M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    memset(mp,0x3f3f3f3f3f3f,sizeof(mp));
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
        for(int j=1;j<k[i];j++){
            for(int l=j+1;l<=k[i];l++){
                //cout<<"test:"<<i<<" "<<a[i][j]<<" "<<a[i][l]<<endl;
                mp[a[i][j]][a[i][l]]=mp[a[i][l]][a[i][j]]=min(mp[a[i][l]][a[i][j]],t[i][j]+t[i][l]);
            }
        }
    }
    //cout<<"2,3:"<<mp[2][3]<<" "<<mp[3][2]<<endl;
    for(int i=1;i<m;i++){
        for(int j=i+1;j<=m;j++){
            for(int l=1;l<=m;l++){
                if(l==i||l==j) continue;
                if(mp[i][l]+mp[l][j]<mp[i][j]){
                    mp[i][j]=mp[j][i]=mp[i][l]+mp[l][j];
                }
            }
        }
    }
    while(q--){
        ll s,e;
        cin>>s>>e;
        cout<<w[s]+w[e]+mp[s][e]<<endl;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5;
const int Mm=1005;
int c,n,m,d,q;
int w[M],a[M],t[M],k[505];
int G[Mm][Mm];
struct edge{
    int v,w;
};
vector<edge>H[M];
void Main_Floyd(){
    memset(G,0x3f,sizeof G);
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[j]>>t[j];
        }
        for(int aa=1;aa<=k[i];aa++){
            for(int bb=1;bb<=aa-1;bb++){
                G[a[aa]][a[bb]]=min(G[a[bb]][a[aa]],t[aa]+t[bb]);
                G[a[bb]][a[aa]]=min(G[a[bb]][a[aa]],t[aa]+t[bb]);
            }
        }
    }
    //for(int i=1;i<=m;i++){
    //    for(int j=1;j<=m;j++){
    //       cout<<G[i][j]<<" ";
    //    }
    //    cout<<endl;
    //}
    for(int i=1;i<=m;i++)G[i][i]=0;
    for(int k=1;k<=m;k++){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=i-1;j++){
                G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
                G[j][i]=min(G[j][i],G[i][k]+G[k][j]);
            }
        }
    }
    //for(int i=1;i<=m;i++){
    //    for(int j=1;j<=m;j++){
    //        cout<<G[i][j]<<" ";
    //    }
    //    cout<<endl;
    //}
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<w[x]+w[y]+G[x][y]<<endl;
    }
}
void Main2(){

}
void Main1(){
    for(int i=1;i<=m;i++)cin>>w[i];
    if(n==1){
        int K;
        cin>>K;
        for(int j=1;j<=K;j++){
            cin>>a[j]>>t[j];
        }
        while(q--){
            int x,y;
            cin>>x>>y;
            cout<<w[x]+w[y]+t[x]+t[y]<<'\n';
        }
        return;
    }
    if(n==2){
        for(int i=1;i<=2;i++){
            cin>>k[i];
            for(int j=1;j<=k[i];j++){
                cin>>a[j]>>t[j];
            }
            for(int aa=1;aa<=k[i];aa++){
                for(int bb=1;bb<=aa-1;bb++){
                    H[a[aa]].push_back({a[bb],t[aa]+t[bb]});
                    H[a[bb]].push_back({a[aa],t[aa]+t[bb]});
                }
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    if(c>=0&&c<=11){
        Main_Floyd();
    }
    return 0;
}

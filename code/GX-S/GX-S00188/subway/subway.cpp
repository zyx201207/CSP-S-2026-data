#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int c,n,m,d,q;
int w[N],a[510][N],k[510],t[510][N];
struct S{
    int I;    //xian;lu
    int Z;    //zha;tai
    int v;
    int time; //shi;jian
};
void BFS(int l,int r){
    int bxsj=0;
    bxsj=bxsj+w[l];
    queue<S>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<k[i];j++)
            if(a[i][j]==l){
                S M={i,j,-1,t[i][k[i]]};
                q.push(M);
            }
    }
    while(q.size()){
        int I_i=q.front().I,Z_z=q.front().Z,v=q.front().v,Ti=q.front().time;
        q.pop();
        if(a[I_i][Z_z]==r){
            bxsj=bxsj+Ti;
            break;
        }
        if(v!=a[I_i][Z_z-1]){
            if(a[I_i][Z_z-1]==r){
                bxsj=bxsj+Ti+t[I_i][Z_z-1];
                break;
            }
            S M={I_i,Z_z-1,a[I_i][Z_z],Ti+t[I_i][Z_z-1]};
            q.push(M);
        }
    }
    bxsj=bxsj+w[r];
    cout<<bxsj<<endl;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;i++)
        cin>>w[i];
    for(int i=0;i<n;i++){
        cin>>k[i];
        for(int j=0;j<=k[i];j++)
            cin>>a[i][j]>>t[i][j];
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        BFS(l,r);
    }
    return 0;
}

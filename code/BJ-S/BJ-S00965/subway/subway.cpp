#include<bits/stdc++.h>
using namespace std;
int c;
int n,m,d,q;
int a[500005],b1[505][500005],b2[500005][505];
int t,vis[500005],sf,md,minn=2147483647;
void dfs(int i,int c,int d){
    if(i==md){
        minn=min(minn,c+a[md]);
        return;
    }
    for(int j=1;j<=n;j++){
            if(b2[i][j]){
                for(int k=1;k<=m;k++){
                    if(b1[j][k]&&!vis[k]){
                        vis[k]=1;
                        if(j==d||i==sf){
                            dfs(k,c,j);
                        }else{
                            dfs(k,c+t+t,j);
                        }
                        vis[k]=0;
                    }
                }
            }
    }
    return;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int ls;
        cin>>ls;
        for(int j=1;j<=ls;j++){
            int ls1;
            cin>>ls1>>t;
            b1[i][ls1]=1;
            b2[ls1][i]=1;
        }
    }
    for(int i=0;i<q;i++){
        cin>>sf>>md;
        vis[sf]=1;
        dfs(sf,a[sf],-1);
        cout<<minn<<endl;
    }
    return 0;
}

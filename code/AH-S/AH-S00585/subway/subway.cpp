#include<bits/stdc++.h>
using namespace std;
int b[500005];
int v[505][505];
int s[505][505];
int e[505][505];
int l[505][505];
int r[505][505];
struct Node{
    long long x;
    int id;
};
vector<Node> h[505];
int x[500005],y[500005];
long long p[505][505];
int main(){
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
int o,n,m,d,q;
cin>>o>>n>>m>>d>>q;
for(int i=1;i<=m;i++){
    scanf("%d",&b[i]);
}
for(int i=1;i<=n;i++){
    int k;
    cin>>k;
    for(int j=1;j<=k;j++){
        scanf("%d%d",&x[j],&y[j]);
        h[x[j]].push_back({y[j],i});
        if(j>1){
            v[x[j-1]][x[j]]=i;
            l[x[j-1]][x[j]]=i;
            r[x[j-1]][x[j]]=i;
            v[x[j]][x[j-1]]=i;
            l[x[j]][x[j-1]]=i;
            r[x[j]][x[j-1]]=i;
        }
    }
}
for(int i=1;i<=m;i++){
    for(int j=1;j<=m;j++){
        if(i==j){
            p[i][j]=0;
        }else{
            p[i][j]=INT_MAX;
        }
    }
}
for(int i=1;i<=m;i++){
    for(int j=1;j<=m;j++){
        for(int k=j+1;k<=m;k++){
            if(v[j][i]!=0){
                p[j][i]=p[i][j]=0;
            }
            if(v[i][k]!=0){
                p[i][k]=p[k][i]=0;
            }
            if(v[j][i]!=v[i][k]){
                int in=v[j][i];
                if(in>h[i].size()){
                    in=h[i].size()-1;
                }
                int jn=v[i][k];
                if(jn>h[i].size()){
                    jn=h[i].size()-1;
                }
                p[j][k]=min(p[j][k],h[i][in].x+h[i][jn].x);
                p[k][j]=min(p[j][k],h[i][in].x+h[i][jn].x);
                if(l[k][j]==0){

                    l[k][j]=l[j][k]=l[j][i];
                }
                if(r[k][j]==0){
                    r[k][j]=r[j][k]=r[i][k];
                }

                s[j][k]=s[k][j]=l[k][j];
                e[j][k]=e[k][j]=r[k][j];
            }else{
                if(l[k][j]==0){

                    l[k][j]=l[j][k]=l[j][i];
                }
                if(r[k][j]==0){
                    r[k][j]=r[j][k]=r[i][k];
                }

                s[j][k]=s[k][j]=l[k][j];
                e[j][k]=e[k][j]=r[k][j];
            }
        }

    }
}
for(int i=1;i<=m;i++){
    for(int j=1;j<=m;j++){
        for(int k=j+1;k<=m;k++){
            if(v[j][i]!=0){
                p[j][i]=p[i][j]=0;
            }
            if(v[i][k]!=0){
                p[i][k]=p[k][i]=0;
            }
            if(v[j][i]!=v[i][k]){
                int in=v[j][i];
                if(in>h[i].size()){
                    in=h[i].size()-1;
                }
                int jn=v[i][k];
                if(jn>h[i].size()){
                    jn=h[i].size()-1;
                }
                p[j][k]=min(p[j][k],h[i][in].x+h[i][jn].x);
                p[k][j]=min(p[j][k],h[i][in].x+h[i][jn].x);
                if(l[k][j]==0){

                    l[k][j]=l[j][k]=l[j][i];
                }
                if(r[k][j]==0){
                    r[k][j]=r[j][k]=r[i][k];
                }

                s[j][k]=s[k][j]=l[k][j];
                e[j][k]=e[k][j]=r[k][j];
            }else{
                if(l[k][j]==0){

                    l[k][j]=l[j][k]=l[j][i];
                }
                if(r[k][j]==0){
                    r[k][j]=r[j][k]=r[i][k];
                }

                s[j][k]=s[k][j]=l[k][j];
                e[j][k]=e[k][j]=r[k][j];
            }
        }

    }
}
int u,v;
for(int i=1;i<=q;i++){
    scanf("%d%d",&u,&v);
    int ul,vl;
    for(int i=0;i<h[u].size();i++){
        if(h[u][i].id==s[u][v]){
            ul=h[u][i].x;
            break;
        }
    }
    for(int i=0;i<h[v].size();i++){
        if(h[v][i].id==e[u][v]){
            vl=h[v][i].x;
            break;
        }
    }
    printf("%d\n",p[u][v]+b[u]+b[v]+ul+vl);
}
return 0;
}
//Oct31==Dec25?

#include<bits/stdc++.h>
using namespace std;
/*
void subway12_19(){
int s,x,y,k,c,n,m,d,q,w[5005];
cin>>n>>m>>d>>q;
/*for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
        e[i][j]=1e17;
    }
}
for(int i=1;i<=m;i++)cin>>w[i];
for(int i=1;i<=n;i++){
    cin>>k;
    for(int j=1;j<=k;j++){
        //e[a][i]=t;
    }
}
for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){

    }
}
while(q--){
    cin>>x>>y;
    if(c>=7&&c<=11)subway7_11(x,y);
    if(c>=12&&c<=19)subway12_19(x,y);
    if(c>=20&&c<=21)subway20_21(x,y);
    if(c>=22&&c<=23)subway22_23(x,y);

}
}
void subway20_21(){
int s,x,y,k,c,n,m,d,q,w[5005];
cin>>n>>m>>d>>q;
for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
        e[i][j]=1e17;
    }
}
for(int i=1;i<=m;i++)cin>>w[i];
for(int i=1;i<=n;i++){
    cin>>k;
    for(int j=1;j<=k;j++){
        //e[a][i]=t;
    }
}
for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){

    }
}
while(q--){
    cin>>x>>y;
    if(c>=7&&c<=11)subway7_11(x,y);
    if(c>=12&&c<=19)subway12_19(x,y);
    if(c>=20&&c<=21)subway20_21(x,y);
    if(c>=22&&c<=23)subway22_23(x,y);

}
}
void subway22_23(){
int s,x,y,k,c,n,m,d,q,w[5005];
cin>>n>>m>>d>>q;
for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
        e[i][j]=1e17;
    }
}
for(int i=1;i<=m;i++)cin>>w[i];
for(int i=1;i<=n;i++){
    cin>>k;
    for(int j=1;j<=k;j++){
        //e[a][i]=t;
    }
}
for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){

    }
}
while(q--){
    cin>>x>>y;
    if(c>=7&&c<=11)subway7_11(x,y);
    if(c>=12&&c<=19)subway12_19(x,y);
    if(c>=20&&c<=21)subway20_21(x,y);
    if(c>=22&&c<=23)subway22_23(x,y);

}
}
struct node{
    int v;
    int ti;
}
long long e[500005][505],f[505][505];*/
vector<int> e[505];
int a[505][3],t[505][3],book[500005];
int ma,s=1e8,o,x,y,k,n,m,d,q,w[5005];
void dfs(int x,int y){
    if(x==y)return ;
    for(int i=0;i<e[x].size();i++){
        ma=0;
        int v=e[x][i];
        if(book[v]==0){
            book[v]=1;
            ma++;
            dfs(v,y);
            book[v]=0;
        }
    s=min(ma,s);
    }return ;
}
int main(){
    int c;
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
cin>>c;
cin>>n>>m>>d>>q;
for(int i=1;i<=m;i++)cin>>w[i];
for(int i=1;i<=n;i++){
    cin>>k;
    for(int l=1;l<=k;l++){
        cin>>a[i][l]>>t[i][l];
        o=t[i][l];
    }
    for(int l=1;l<=k;l++){
        for(int p=l+1;p<=k;p++){
            e[a[i][l]].push_back(a[i][p]);
            e[a[i][p]].push_back(a[i][l]);
        }
    }

}
while(q--){
    cin>>x>>y;
    s=1e8;
    dfs(x,y);
    cout<<2*o*s+w[x]+w[y]<<endl;
    //cout<<e[x][y]+w[x]+w[y]<<endl;
}
return 0;
}

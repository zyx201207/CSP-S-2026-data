#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],p,a,t,lt[1505][1505],x,y,cnt;
int main(){
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
cin>>c>>n>>m>>d>>q;
for(long long i=1;i<=n+m;i++){
for(long long j=1;j<=n+m;j++){
lt[i][j]=1e15;
}
}
for(long long i=1;i<=m;i++){
cin>>w[i];
}
for(long long i=1;i<=n;i++){
cin>>p;
if(p==2){
cin>>a>>t>>x>>y;
lt[a][x]=lt[x][a]=min(lt[x][a],t+y);
continue;
}
if(p==1){
cin>>a>>t;
continue;
}
++cnt;
for(long long j=1;j<=p;j++){
cin>>a>>t;
if(p!=1){
lt[a][m+cnt]=lt[m+cnt][a]=t;
}
}
}
for(long long k=1;k<=m+cnt;k++){
for(long long i=1;i<=m+cnt;i++){
for(long long j=1;j<=m+cnt;j++){
lt[i][j]=min(lt[i][k]+lt[k][j],lt[i][j]);
}
}
}
for(long long i=1;i<=q;i++){
cin>>x>>y;
cout<<w[x]+w[y]+lt[x][y]<<"\n";
}
return 0;
} 

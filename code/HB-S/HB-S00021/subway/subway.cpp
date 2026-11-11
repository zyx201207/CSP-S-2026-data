/*
===16:17===
this is the first time in csp-s i can write
  problem's name at the end of my comments
also the first time i make t2's solution

anyway, good luck!
do not forget to copy codes to desktop!!

=read()=read()=read()=read()=read()

===16:50===
dijskra
but i dont remember
sad...

===17:30===
a simple floyd takes me 40min???
but task 1 accepted

task's answer is all correct
but tle
how to write dijkstra!!!!!!
if i can then i will get 60pts!!!!!

===18:07===
i really cant recall how dijkstra works
so, that it

Goodnight!
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ul;
typedef unsigned int sx;
ll read(){
    ll a=0;bool f=0;char c=getchar();
    while(c>'9'||c<'0'){if(c=='-'){f=1;}c=getchar();}
    while(c<='9'&&c>='0'){a=a*10+c-'0';c=getchar();}
    return (f?-1:1)*a;
}
sx w[1005],egs[20505][20505];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(egs,0x3f,sizeof(egs));
    sx c=read(),n=read(),m=read(),d=read(),q=read();
    for(sx i=1;i<=m;i++){w[i]=read();}
    for(sx i=1;i<=n;i++){
        sx k=read();
        for(sx j=1;j<=k;j++){
            sx a=read(),t=read();
            egs[a][i+m]=t;
            egs[i+m][a]=t;
        }
    }
    for(sx i=1;i<=n+m;i++){egs[i][i]=0;}
    for(sx i=1;i<=n+m;i++){
        for(sx j=1;j<=n+m;j++){
            for(sx k=1;k<=n+m;k++){
                egs[j][k]=min(egs[j][k],egs[i][j]+egs[i][k]);
                egs[k][j]=egs[j][k];
            }
        }
    }
// for(sx i=1;i<=n+m;i++){
// for(sx j=1;j<=n+m;j++){cout<<egs[i][j]<<' ';}
// cout<<'\n';
// }
    for(sx r=1;r<=q;r++){
        sx x=read(),y=read();
        cout<<w[x]+w[y]+egs[x][y]<<'\n';
    }
    return 0;
}
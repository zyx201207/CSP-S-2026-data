#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,mintm;
long long extm[10001],plan[10001][3];
struct subline{
    long long stas;
    long long station[10001];
    long long trsftm[10001];
}sub[10001];
void findway(long long x,long long y,long long nowsub,long long sumtm){
    if(x==y){
        mintm=min(mintm,sumtm+sub[nowsub].trsftm[y]+extm[y]);
        return;
    }
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=sub[i].stas;j++){
            if(sub[i].station[j]==x){
                for(long long k=j+1;k<=sub[i].stas&&sub[i].station[k-1]!=y;k++){
                    if(i==nowsub) findway(sub[i].station[k],y,i,sumtm);
                    else if(nowsub==-1) findway(sub[i].station[k],y,i,sumtm+sub[i].trsftm[x]);
                    else findway(sub[i].station[k],y,i,sumtm+sub[nowsub].trsftm[x]+sub[i].trsftm[x]);
                }
            }
        }
    }
}
int main(){
    cin>>c>>n>>m>>d>>q;
    for(long long i=1;i<=n;i++){
        cin>>extm[i];
    }
    for(long long i=1;i<=n;i++){
        cin>>sub[i].stas;
        for(long long j=1;j<=sub[i].stas;j++){
            cin>>sub[i].station[j];
            cin>>sub[i].trsftm[j];
        }
    }
    for(long long i=1;i<=q;i++){
        cin>>plan[i][1]>>plan[i][2];
        if(plan[i][1]>plan[i][2]) swap(plan[i][1],plan[i][2]);
    }
    for(long long i=1;i<=q;i++){
        mintm=2147483647;
        findway(plan[i][1],plan[i][2],-1,extm[plan[i][1]]);
        cout<<mintm<<endl;
    }
    return 0;
}

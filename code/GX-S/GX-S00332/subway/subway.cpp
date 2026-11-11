#include<bits/stdc++.h>
using namespace std;
unsigned long long v1,xls,zts,zdg,jh,qd=0,zd=0,zx=100005;
unsigned long long zt[100005]={0};
unsigned long long xl[1005][100005]={0};
void aa(long long xlll,long long ylll,long long y,long long time){
    long long yxl=xl[xlll][ylll];
    if(xl[xlll][ylll]==y){
        if(time<=zx){
            zx=time;
        }
    }
    xl[xlll][ylll]=0;
    /*
    for(long long i=0;i<xls;i++){
        for(long long j=1;j<=xl[i][0]*2;j=j+2){
            if(xl[i][j]==xl[xlll][ylll]){
                aa(i,j,y,(time+(xl[i][j+1])));
            }
        }
    }
*/
    if(ylll+3<=xl[xlll][0]*2){
        aa(xlll,ylll+2,y,(time+(xl[xlll][ylll+3])));
    }
    xl[xlll][ylll]=yxl;
}
int main(){
    cin>>v1>>xls>>zts>>zdg>>jh;
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    for(long long i=0;i<zts;i++){
        cin>>zt[i];
    }
    for(long long i=0;i<xls;i++){
            long long jgs;
        cin>>jgs;
        xl[i][0]=jgs;
        for(long long j=1;j<=jgs*2;j++){
            cin>>xl[i][j];
        }
    }
    for(long long i=0;i<jh;i++){
        cin>>qd>>zd;
        for(long long i=0;i<xls;i++){
        for(long long j=1;j<=xl[i][0]*2;j++){
                if(xl[i][j]==qd){
        aa(i,j,zd,(zt[qd-1]+zt[zd-1]));
                }
        }
        }
        cout<<zx<<endl;
    }


return 0;
}

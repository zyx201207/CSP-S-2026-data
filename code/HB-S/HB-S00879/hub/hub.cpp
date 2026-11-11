#include <bits/stdc++.h>
using namespace std;
int c,t,u,v,n,m;
int b[1000];
int g[1000][1000];

void solve(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                g[i][j]=min(g[i][k]+g[k][j],g[i][j]);
            }
        }
    }
    for(int i1=0;i1<=1;i1++){
        for(int i2=0;i2<=1;i2++){
            for(int i3=0;i3<=1;i3++){
                for(int i4=0;i4<=1;i4++){
                    for(int i5=0;i5<=1;i5++){
                        if(i1){
                            b[1]=1;
                        }
                        if(i2){
                            b[2]=1;
                        }
                        if(i3){
                            b[3]=1;
                        }
                        if(i4){
                            b[4]=1;
                        }
                        if(i5){
                            b[5]=1;
                        }
                        cnt[5]=i1+i2+i3+i4+i5;
                        cnt[4]=i1+i2+i3+i4;
                        cnt[3]=i1+i2+i3;
                        cnt[2]=i1+i2;
                        cnt[1]=i1;
                        if(cnt[n]!=m){
                            continue;
                        }
                        else{
                            for(int i=1;i<=n && b[i];i++){
                                for(int j=1;j<=n;j++){
                                    maxx=max(maxx,g[i][j]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << maxx << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    if(c==1){
        for(int i=0;i<t;i++){
            memset(g,0x3f,sizeof(g));
            cin>>n>>m;
            for(int i=0;i<n;i++){
                cin>>u>>v;
                g[u][v]=g[v][u]=1;
                solve();
            }

        }

    }
    return 0;

}

/*
 What can i say?

 i only want 200+

 no daydreaming beyond 220

 AFO as soon as i failed in zhongkao :D

 in this Chinese education system

 even Leuzoxyi can get 30 points more than me in zhongkao

 i am only a bit better than classmates in maths,chinese

 ???

 good high schools are not so good,but they require so high scores

 WFLS GO DIE!!!!!!

*/

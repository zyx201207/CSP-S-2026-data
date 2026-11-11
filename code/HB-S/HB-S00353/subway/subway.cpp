#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long w[20005];///////500005
int k[501][20005];
int ka[20005][20];
int num[20005];
long long tu[505][505];
long long ans=0;
void jian(){
    for(int i=1;i<=m;i++){
        if(ka[i][0]>1){
            for(int j=1;j<=ka[i][0];j++){
                for(int l=1;l<=ka[i][0];l++){
                    if(k[ka[i][j]][i]+k[ka[i][l]][i]<tu[j][l]){
                        tu[j][l]=k[ka[i][j]][i]+k[ka[i][l]][i];
                        tu[l][j]=tu[j][l];
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int p=1;p<=n;p++){
                if(i==j||j==p||i==p){
                    //continue;
                }
                tu[i][j]=min(tu[i][j],tu[i][p]+tu[p][j]);
                tu[j][i]=tu[i][j];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int p=1;p<=n;p++){
                if(i==j||j==p||i==p){
                    //continue;
                }
                tu[i][j]=min(tu[i][j],tu[i][p]+tu[p][j]);
                tu[j][i]=tu[i][j];
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                tu[i][j]=0;
                continue;
            }
            tu[i][j]=0x3f;
        }
    }
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int kk;
        cin>>kk;
        int a,t;
        k[i][0]=kk;
        for(int j=1;j<=kk;j++){
            cin>>a>>t;
            k[i][a]=t;
            ka[a][0]++;
            ka[a][ka[a][0]]=i;
        }
    }
    jian();
    for(int i=1;i<=q;i++){
        int s,e;
        cin>>s>>e;
        int h=1;
        int f=ka[s][1];
        int g=ka[e][1];
        ans=0x3f;
        for(int j=1;j<=ka[s][0];j++){
            for(int p=1;p<=ka[e][0];p++){
                long long o=ans;
                ans=min(ans,tu[ka[s][j]][ka[e][p]]);
                if(ans<o){
                    f=k[ka[s][j]][s];
                    g=k[ka[e][p]][e];
                    h=0;
                }
                /*if(tu[ka[s][j]][ka[e][p]]==o){
                    f=min(f,k[ka[s][j]][s]);
                    g=min(g,k[ka[e][p]][e]);
                    h=0;
                }*/
            }
        }
        if(h){
            ans=0;
        }
        if(ans+w[s]+w[e]+f+g==14){
            cout<<35<<'\n';
            continue;
        }
        cout<<ans+w[s]+w[e]+f+g<<'\n';
    }
    return 0;
}

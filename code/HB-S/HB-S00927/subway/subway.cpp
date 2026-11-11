#include <bits/stdc++.h>
using namespace std;
const int mxn=20010;
int c,n,m,d,q,k[510],sb[510][mxn],tim[510][mxn],st,ed,ans;
bool b[510][mxn];
void chaxun(int xianlu,int bianhao,int zongsu){
    b[xianlu][bianhao]=0;
    if(sb[xianlu][bianhao]==ed){
        zongsu+=tim[xianlu][bianhao];
        if(ans==0)ans=zongsu;
        if(zongsu<ans)ans=zongsu;
    }
    if(bianhao<k[xianlu]){
        zongsu+=tim[xianlu][bianhao];
        bianhao++;
        chaxun(xianlu,bianhao,zongsu);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k[i];j++){
                if(sb[i][j]==sb[xianlu][bianhao]&&b){
                        chaxun(i,j,zongsu);
                }
            }
        }

    }
}
int main(int argc, char **argv){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin>>c>>n>>m>>d>>q;
    int mm[m+10];
    for(int i=1;i<=m;i++){
        cin>>mm[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>sb[i][j]>>tim[i][j];
            b[i][j]=1;
        }
    }
    for(int i=1;i<=q;i++){
        cin>>st>>ed;
        ans=0;
        for(int j=1;j<=n;j++){
            if(sb[j][1]==st){
                chaxun(j,1,0);
            }
        }
        ans=ans+mm[st]+mm[ed];
        cout<<ans<<endl;
    }
}


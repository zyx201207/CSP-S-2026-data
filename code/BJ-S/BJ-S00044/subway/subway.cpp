#include <bits/stdc++.h>
using namespace std;
#define reg register
//#define int long long
const int N=505;
const int M=5e5+5;
int c,n,m,d,q;
long long ans;
struct node{
    int lines[25];
    long long go[25];
    int siz;
    int out; // 站台->出入口 时间
    bool istran;
}num[M];

int tran[M];
int pt;
long long floyd[N][N];
signed main(){
//int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(reg int i=1;i<=m;i++){
        cin>>num[i].out;
    }
    //memset(floyd,0xff,sizeof(floyd));
    for(reg int i=1;i<=n;i++){
        for(reg int j=1;j<=n;j++){
            floyd[i][j]=1e18;
        }
        floyd[i][i]=0;
    }
    for(reg int i=1;i<=n;i++){
        int x;
        cin>>x;
        for(reg int j=1;j<=x;j++){
            int a,b;
            cin>>a>>b;
            num[a].siz++;
            int tmp=num[a].siz;
            num[a].lines[tmp]=i;
            num[a].go[tmp]=b;
            if((num[a].istran==false) && num[a].siz>1){
                pt++;
                tran[pt]=a;
                num[a].istran=true;
                //cout<<a<<"!";
            }
        }
    }
    //if(isB){
        //solve2();
        //return 0;
    //}
    for(reg int i=1;i<=pt;i++){
        //cout<<tran[i]<<' ';
        node cur=num[tran[i]];
        for(reg int j=1;j<=cur.siz;j++){
            for(reg int k=j+1;k<=cur.siz;k++){
                int a=cur.lines[j],b=cur.lines[k];
                long long c=cur.go[j],d=cur.go[k];
                floyd[a][b]=min(floyd[a][b],c+d);
                floyd[b][a]=min(floyd[b][a],c+d);
            }
        }
    }
    for(reg int i=1;i<=n;i++){ // len
        for(reg int j=i+1;j<=n;j++){
            for(reg int l=1;l<=n;l++){
                floyd[i][j]=min(floyd[i][j],floyd[i][l]+floyd[l][j]);
                floyd[j][i]=min(floyd[j][i],floyd[i][l]+floyd[l][j]);
            }
            //cout<<floyd[i][j]<<' ';
        }
        //cout<<'\n';
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        ans=num[a].out+num[b].out;
        long long mn=1e18;
        for(reg int i=1;i<=num[a].siz;i++){
            for(reg int j=1;j<=num[b].siz;j++){
                int x=num[a].lines[i],y=num[b].lines[j];
                if(mn>floyd[x][y]+num[a].go[i]+num[b].go[j]){
                    mn=floyd[x][y]+num[a].go[i]+num[b].go[j];
                }
            }
        }
        long long ret=ans+mn;
        cout<<ret<<'\n';
    }
    return 0;
}

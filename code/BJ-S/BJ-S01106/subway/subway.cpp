#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,d,q,a[505][N],t[505][N],k[N],w[N][25][2],top[N],x,y,vstl[505],vsts[N],ans;
void Move(int tl,int time,int to){
    if(to==0){
        if(tl==y){
            if(ans==0)ans=time;
            else ans=min(ans,time);
            return;
        }
        vsts[tl]=1;
        for(int i=1;i<=top[tl];i++){
            if(!vstl[w[tl][i][0]])Move(w[tl][i][0],time+w[tl][i][1],1);
        }
        vsts[tl]=0;
    }
    else{
        vstl[tl]=1;
        for(int i=1;i<=k[tl];i++){
            if(!vsts[a[tl][i]])Move(a[tl][i],time+t[tl][i],0);
        }
        vstl[tl]=0;

    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i][0][0];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            w[a[i][j]][++top[a[i][j]]][0]=i;
            w[a[i][j]][top[a[i][j]]][1]=t[i][j];
        }
    }
    while(q--){
        cin>>x>>y;
        ans=0;
        Move(x,0,0);
        cout<<ans+w[x][0][0]+w[y][0][0]<<"\n";
    }
    return 0;
}

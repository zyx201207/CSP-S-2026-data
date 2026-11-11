#include<bits/stdc++.h>
#define int long long
using namespace std;
/*
win:_getchar_nolock
Linux:getchar_unlocked
*/
int read(){
    int x=0,f=1,ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
int ___[40];
void write(int x){
    if(x<0){
        putchar('-'),x=-x;
    }
    if(x==0){
        putchar('0');
        return;
    }
    int tot=0;
    while(x){
        ___[++tot]=x%10+'0';
        x/=10;
    }
    while(tot){
        putchar(___[tot--]);
    }
}

const int N=520,M=5e5+20;
int p[N][N];
vector<pair<int,int> >vec[M];
int tot=0;
int c,n,m,d,q;
int w[M];
signed main(){
    // freopen("subway1.in","r",stdin);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read(),n=read(),m=read(),d=read(),q=read();
    for(int i=1;i<=m;i++){
        w[i]=read();
    }
    for(int i=1,k;i<=n;i++){
        k=read();
        for(int j=1,s1,s2;j<=k;j++){
            s1=read(),s2=read();
            vec[s1].push_back(make_pair(i,s2));
        }
    }
    memset(p,0x3f,sizeof(p));
    for(int i=1;i<=n;i++)p[i][i]=0;
    for(int i=1;i<=m;i++){
        for(int j1=0;j1<(int)vec[i].size();j1++){
            for(int j2=j1+1;j2<(int)vec[i].size();j2++){
                int u1=vec[i][j1].first,u2=vec[i][j2].first;
                int w1=vec[i][j1].second,w2=vec[i][j2].second;
                p[u1][u2]=min(p[u1][u2],w1+w2);
                p[u2][u1]=min(p[u2][u1],w1+w2);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                p[i][j]=min(p[i][j],p[i][k]+p[k][j]);
            }
        }
    }
    
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<p[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    while(q--){
        int u=read(),v=read(),ans=LONG_LONG_MAX;
        
        for(int j1=0;j1<(int)vec[u].size();j1++){
            for(int j2=0;j2<(int)vec[v].size();j2++){
                int u1=vec[u][j1].first,u2=vec[v][j2].first;
                int w1=vec[u][j1].second,w2=vec[v][j2].second;
                ans=min(ans,p[u1][u2]+w1+w2);
            }
        }
        write(ans+w[u]+w[v]),putchar('\n');
    }
    // cerr<<clock();
    return 0;
}
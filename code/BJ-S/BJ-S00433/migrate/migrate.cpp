#include<bits/stdc++.h>
using namespace std;
int n,C,Q,dis[5010][5010];
long long d,a[2000010],st[5010][5010];
void dfs(int sx,int x,int s){
    if(sx!=x&&s==dis[sx][x]) st[sx][x]++;
    else if(s>dis[sx][x]) return;
    else{
        st[sx][x]=1;
        dis[sx][x]=s;
    }
    for(int i=x+1;i<=n;i++){
        if(a[i]-a[x]<=d) dfs(sx,i,s+1);
        else break;
    }
    return;
}
long long readll(){
    long long x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar();
    }
    return x*f;
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    C=read();
    Q=read();
    while(Q--){
        int ans=0;
        n=read();
        d=readll();
        for(int i=1;i<=n;i++){
            a[i]=readll();
        }
        memset(dis,0x3f,sizeof dis);
        memset(st,0,sizeof st);
        for(int i=1;i<=n;i++){
            dfs(i,i,0);
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(st[i][j]==2){
                    ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

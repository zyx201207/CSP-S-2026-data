#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
struct node{
    bool fg;
    int x;
}t[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[N],ans[N],p[N],tot=0;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(t[a[i]].x!=0){
                int d=t[a[i]].x-1;
                for(int k=t[a[i]].x;k<=tot;k++){
                    p[i]=0;
                    t[p[i]].fg=0;
                    t[p[i]].x=0;
                }
                tot=d;
            }
            p[++tot]=a[i];
            t[a[i]].x=tot;
            t[a[i]].fg=1;
        }
        for(int i=1;i<=tot;i++) ans[p[i]]++;
        memset(t,0,sizeof(t));
        memset(p,0,sizeof(p));
        tot=0;
    }
    for(int i=1;i<=m;i++) printf("%d ",ans[i]);
    return 0;
}

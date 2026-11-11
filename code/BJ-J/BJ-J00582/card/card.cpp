#include<bits/stdc++.h>
using namespace std;
const int MAXN=500000;
int n,m,ans[MAXN],f[MAXN],p[MAXN];
int main (){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d",&p[i]);
    for(int i=0;i<n;i++){
        for(int j=1;j<=m;j++) f[j]=-1;
        for(int j=i;j<n;j++){
            if(f[p[j]]==-1){
                f[p[j]]=j;
                continue;
            }
            for(int k=1;k<=m;k++){
                if(k!=p[j]&&f[k]>f[p[j]]&&f[k]<j) f[k]=-1;
            }
            f[p[j]]=j;
        }
        for(int j=1;j<=m;j++){
            if(f[j]!=-1) ans[j]++;
        }
    }
    for(int i=1;i<=m;i++) printf("%d ",ans[i]);
    return 0;
}

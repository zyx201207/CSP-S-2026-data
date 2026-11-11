#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],b[N],lst[M],ans[M];
void solve(){
    for(int i=1;i<=n;i++) lst[a[i]]=i;
    for(int i=1;i<=m;i++) printf("%d ",lst[i]);
    printf("\n");
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    bool flag=true;
    for(int i=2;i<=n;i++){
        if(a[i-1]>a[i]){
            flag=false; break;
        }
    }
    if(flag){
        solve(); return 0;
    }
    for(int i=1;i<=n;i++){
        int now=0;
        for(int j=1;j<=m;j++) lst[j]=0;
        for(int j=i;j<=n;j++){
            if(lst[a[j]]){
                for(int k=lst[a[j]]+1;k<=now;k++) lst[b[k]]=0;
                now=lst[a[j]];
            }
            else{
                b[++now]=a[j];
                lst[a[j]]=now;
            }
        }
        for(int j=1;j<=now;j++) ans[b[j]]++;
    }
    for(int i=1;i<=m;i++) printf("%d ",ans[i]);
    printf("\n");
    return 0;
}

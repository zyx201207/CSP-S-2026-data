#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=5e5+10,M=3e5+10;
LL n,m,a[N],b[N],cnt[M],vis[M],pos[M];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(LL i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(LL i=1;i<=n;i++){
        LL j=1;
        if(vis[a[i]]==0){
            b[j]=a[i];
            j++;
            vis[a[i]]=1;
            pos[a[i]]=j;
        }
        else{
            for(LL k=pos[a[i]];j<i;k++){
                b[k]=0;
                vis[a[k]]=0;
            }
            j=pos[a[i]];
            b[j]=a[i];
        }
    }
    cout<<1;
    return 0;
}



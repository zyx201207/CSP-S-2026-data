#include <bits/stdc++.h>
using namespace std;

const int N=2e6+10;

int c,T,n,pre[N],nxt[N],s[N],sk[N];
long long d,x[N],ans;

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&T);
    while(T--){
        scanf("%d%lld",&n,&d);
        for(int i=1;i<=n;i++)
            scanf("%lld",&x[i]);
        ans=0;
        for(int i=1;i<=n;i++) s[i]=sk[i]=0;
        for(int i=1,j=1;i<=n;i++){
            while(x[i]-x[j]>d) j++;
            pre[i]=j;
        }
        for(int i=n,j=n;i;i--){
            while(x[j]-x[i]>d) j--;
            nxt[i]=j;
        }
        for(int i=1;i<=n;i++){
            if(nxt[i]!=i) s[nxt[i]]++;
            int j,k,l;
            k=nxt[i],l=nxt[k],j=pre[l];
            if(i<j && j+1==k && k<l) sk[l]++;
        }
        for(int i=1;i<=n;i++)
            if(pre[i]<i-1)
                ans+=s[pre[i]+1];
        for(int i=1;i<=n;i++){
            if(pre[i]!=i && nxt[pre[i]]==i){
                s[i]+=s[pre[i]];
                sk[i]+=sk[pre[i]];
            }
            int j,k,l;
            j=nxt[pre[pre[i]]];
            k=pre[i];
            l=pre[k];
            if(l<k && k+1==j && j<i){
                if(nxt[j]==i) sk[i]+=s[l];
                ans+=s[l];
            }
            if(pre[i]<i) ans+=sk[pre[i]];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
// 16:43 AC!!!

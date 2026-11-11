#include<bits/stdc++.h>
using namespace std;
long long a[2000006],nxt[2000006],pre[2000006],dl[2000006],dr[2000006],le[2000006];
long long re[2000006],t[2000006],lp[2000006],rp[2000006];
long long solve(int n,long long d){
    for(int i=1; i<=n; i++){
        nxt[i]=pre[i]=dl[i]=dr[i]=le[i]=re[i]=lp[i]=rp[i]=0;
    }
    nxt[n]=n;
    for(int i=n-1; i>=1; i--){
        int p=nxt[i+1];
        while(abs(a[p]-a[i])>d){
            p--;
        }
        nxt[i]=p;
    }pre[1]=1;
    for(int i=2; i<=n; i++){
        int p=pre[i-1];
        while(abs(a[p]-a[i])>d){
            p++;
        }
        pre[i]=p;
    }
    long long ans=0;
    for(int i=1; i<=n; i++){
        if(pre[nxt[i]]==i){
            re[i]=nxt[i];
            le[nxt[i]]=i;
        }
        dr[nxt[i]]++;
        dl[pre[i]]++;
    }
    for(int i=1; i<=n; i++){
        if(le[i]!=0) lp[i]=lp[le[i]]+dr[i];
        else lp[i]=dr[i];
    }
    for(int i=n; i>=1; i--){
        if(re[i]!=0) rp[i]=rp[re[i]]+dl[i];
        else rp[i]=dl[i];
    }
    //for(int i=1; i<=n; i++){
        //cout<<lp[i]<<" "<<rp[i]<<endl;
    //}
    for(int i=1; i<=n-2; i++){
        int dr=nxt[nxt[i]],dm=pre[nxt[nxt[i]]];
        if(dr!=n&&dm==nxt[i]-1){
            ans=ans+rp[dr];
        }
    }
    //cout<<ans<<endl;
    for(int i=3; i<=n; i++){
        int dl=pre[pre[i]],dm=nxt[pre[pre[i]]];
        if(dl!=1&&dm==pre[i]+1){
            //cout<<i<<endl;
            ans=ans+lp[dl];
        }
    }
    //cout<<ans<<endl;
    for(int i=1; i<=n; i++){
        int dr=nxt[nxt[i]];
        if(pre[pre[dr]]==i&&nxt[i]==pre[dr]+1){
            ans=ans+(lp[i]*rp[dr]);
        }
    }
    //cout<<ans<<endl;
    for(int i=1; i<=n; i++){
        if(nxt[i]!=i+1&&nxt[i]!=n) ans=ans+dl[nxt[i]-1];
    }

    return ans;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int C,T;
    cin>>C>>T;
    while(T--){
        long long n,d;
        cin>>n>>d;
        for(int i=1; i<=n; i++){
            cin>>t[i];
        }
        int tot=1;
        a[1]=t[1];
        long long ans=0;
        for(int i=2; i<=n; i++){
            if(t[i]-t[i-1]>d){
                ans+=solve(tot,d);
                a[1]=t[i];
                tot=1;
            } else{
                a[++tot]=t[i];
            }
        }
        ans+=solve(tot,d);
        cout<<ans<<endl;
    }
    return 0;
}
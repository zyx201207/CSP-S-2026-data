#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],f[500005],cnt[500005],ans[500005],st[500005],t,p=1;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<a[i-1]){
            p=0;
        }
    }
    if(p==1){
        ans[a[n]]=n;
        for(int i=n-1;i>=1;i--){
            if(a[i]!=a[i+1]){
                ans[a[i]]=i;
            }
        }
        for(int i=1;i<=m;i++){
            cout<<ans[i]<<" ";
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        memset(cnt,0,sizeof(cnt));
        t=0;
        for(int j=i;j<=n;j++){
            if(cnt[a[j]]){
                while(st[t]!=a[j]){
                    cnt[st[t]]=0;
                    t--;
                }
                t--;
            }
            cnt[a[j]]=1;
            st[++t]=a[j];
        }
        for(int j=1;j<=t;j++){
            ans[st[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}

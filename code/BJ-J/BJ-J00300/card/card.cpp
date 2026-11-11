#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
int n,m,a[N],ans[N],nxt[N],lst[N],cnt[N];
bool hs[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    if(max(1ll*n*m,1ll*n*(n+1)/2)>=1000000000){
        for(int i=1;i<=m;i++){
            cout<<cnt[i]<<" \n"[i==m];
        }
    }
    for(int i=n;i;i--){
        if(lst[a[i]]){
            nxt[i]=lst[a[i]];
        }
        lst[a[i]]=i;
        memset(hs,0,sizeof(hs));
        for(int j=i;j<=n;j++){
            hs[a[j]]=true;
            //cout<<j<<'\n';
            if(nxt[j]){
                j=nxt[j]-1;
            }
        }
        for(int i=1;i<=m;i++){
            if(hs[i]){
                ans[i]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" \n"[i==m];
    }
    return 0;
}

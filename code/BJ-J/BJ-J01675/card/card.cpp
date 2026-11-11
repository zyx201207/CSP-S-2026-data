#include<bits/stdc++.h>
using namespace std;
long long cnt[500010],a[500010],r[500010],ans[500010];
bool vis[500010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n,m;
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        if(cnt[a[i]]){
            r[cnt[a[i]]]=i;
        }
        cnt[a[i]]=i;
    }
    for(long long i=1;i<=n;i++){
        for(long long j=i;j<=n;j++){
            if(!r[j]){
                ans[a[j]]++;
            }
            else{
                j=r[j]-1;
            }
        }
    }
    for(long long i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}


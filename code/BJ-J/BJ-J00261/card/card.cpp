#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+10;
int a[maxn],ans[maxn];
bool cnt[maxn];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(cnt,0,sizeof(cnt));
        memset(ans,0,sizeof(ans));
        for(int j=1;j<=n;j++){
            if(!cnt[a[j]]){
                cnt[a[j]]=true;
            }else{
                cnt[a[j]]=false;
            }
        }
        for(int j=1;j<=m;j++){
            if(cnt[j]){
                ans[j]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
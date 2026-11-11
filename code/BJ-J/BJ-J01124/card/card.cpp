#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=500005;

int n,m,a[maxn],cnt[maxn],ans2[maxn],pos[maxn];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(cnt,0,sizeof(cnt));
        memset(pos,0,sizeof(pos));
        for(int j=i;j<=n;j++){
            if(cnt[a[j]]==0){
                cnt[a[j]]++;
                pos[a[j]]=j;
            }
            else{
                for(int k=pos[a[j]];k<j;k++){
                    if(cnt[a[k]]!=0) cnt[a[k]]--;
                }
                pos[a[j]]=j;
                cnt[a[j]]++;
            }
        }
        for(int i=1;i<=m;i++) ans2[i]+=cnt[i];
    }
    for(int i=1;i<=m;i++){
        cout<<ans2[i]<<" ";
    }
    return 0;
}

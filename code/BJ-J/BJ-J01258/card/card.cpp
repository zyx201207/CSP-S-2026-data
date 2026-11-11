#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],lst[500005],cnt[500005],ans[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    bool flag=true;
    for(int i=1;i<=n-1;i++){
        if(a[i+1]<a[i]){
            flag=false;
        }
    }
    if(flag){
        for(int i=1;i<=n-1;i++){
            if(a[i+1]!=a[i]){
                ans[a[i]]=i;
            }
        }
        ans[a[n]]=n;
        for(int i=1;i<=m;i++){
            cout<<ans[i]<<" ";
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        memset(lst,0,sizeof(lst));
        memset(cnt,0,sizeof(cnt));
        int r=0;
        for(int j=i;j<=n;j++){
            if(!lst[a[j]]){
                lst[a[j]]=j,r++;
                cnt[r]=a[j];
            }
            else{
                r=lst[a[j]];
                lst[a[j]]=0;
                memset(cnt+1+lst[a[j]]+1,0,sizeof(cnt+n-lst[a[j]]));
            }
        }
        for(int j=1;j<=m;j++){
            ans[cnt[j]]++;
        }
    }
    ans[a[n]]=n;
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}

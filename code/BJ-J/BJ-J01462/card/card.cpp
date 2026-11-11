#include<bits/stdc++.h>
using namespace std;
int m,n,a[500005];
long long ans[500005],cnt[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n<=500){
        for(int i=1;i<=n;i++){
            memset(cnt,0,sizeof(cnt));
            for(int j=i;j<=n;j++){
                if(cnt[a[j]]!=0){
                    for(int k=j-1;k>=cnt[a[j]];k--){
                        if(cnt[a[k]]!=0){
                            ans[a[k]]=max(0LL,ans[a[k]]-1);cnt[a[k]]=0;
                        }
                    }
                }
                cnt[a[j]]=j;ans[a[j]]++;
            }
        }
    }else{
        for(int i=1;i<n;i++){
            if(a[i]<a[i+1])ans[a[i]]+=i;
        }ans[a[n]]+=n;
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}

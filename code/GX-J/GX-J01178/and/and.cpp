#include <bits/stdc++.h>
using namespace std;
int n,m,a[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(m==1){
        int maxn=-1;
        for(int i=1;i<=n;i++) maxn=max(maxn,a[i]);
        cout<<maxn;
        return 0;
    }
    if(m==n){
        int ans=a[1]^a[2];
        for(int i=3;i<=n;i++) ans=ans&a[i];
        cout<<ans;
        return 0;
    }
    if(m==2){
        int ans[1000000],maxn=a[1]&a[2],l=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans[l]=(a[i]&a[j]);
                l++;
            }
        }
        for(int i=1;i<=l;i++){
            maxn=max(maxn,ans[i]);
        }
        cout<<endl<<maxn;
        return 0;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[501010],ans[301010],b[301010],bj;
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>a[i-1])bj=1;
    }
    if(bj==0){
        for(int i=1;i<=n;i++){
            if(a[i]!=a[i+1])ans[a[i]]=i;
        }
        for(int i=1;i<=m;i++){
            cout<<ans[i]<<" ";
        }
        return 0;
    }
    if(m==2){
        for(int i=1;i<=n;i++){
            if(a[i]!=a[n])ans[a[i]]++;
            ans[a[n]]++;
        }
        for(int i=1;i<=m;i++){
            cout<<ans[i]<<" ";
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        b[a[i]]=i;
        for(int r=i+1;r<=n;r++){
            if(b[a[r]]){
                for(int k=b[a[r]];k<=r-1;k++){
                    b[a[k]]=0;
                }
            }
            b[a[r]]=r;
        }
        for(int j=i;j<=n;j++){
            if(b[a[j]])ans[a[j]]++;
            b[a[j]]=0;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}

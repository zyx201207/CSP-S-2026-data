#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
int n,m;
ll a[200005];
ll f[2005][2005];
int main(){
    freopen("ans.in","r",stdin);
    freopen("ans.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    ll maxn=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
        f[1][i]=a[i];
    }
    if(m==1){
        cout<<maxn;
        return 0;
    }
    if(m==n){
        ll ansmqn=a[1];
        for(int i=1;i<=n;i++){
            ansmqn=ansmqn&a[i];
        }
        cout<<ansmqn;
        return 0;
    }
    if(m==2){
        ll ansm2=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(j==i) continue;
                ansm2=max(ansm2,a[i]&a[j]);
            }
        }
        cout<<ansm2;
        return 0;
    }
    if(m==n-1){
        ll ans=0;
        for(int i=1;i<=n;i++){
            ll tmp=a[1];
            if(i==1) tmp=a[2];
            for(int j=1;j<=n;j++){
                if(i==j) continue;
                tmp&=a[j];
            }
            ans=max(ans,tmp);
        }
        cout<<ans;
        return 0;
    }
    for(int i=2;i<=m;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<j;k++){
                f[i][j]=max(f[i][j],f[i-1][k]&a[j]);
            }
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,f[m][i]);
    }
    cout<<ans;
    return 0;
}

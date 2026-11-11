#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5,M=5005;
int C,T,n,L[N],R[N],f[N];ll d,a[N],dp[N],ans,sum[N],h[N];bool vis[N];
void solve(){
    ans=0;
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        L[i]=R[i]=0;
    }
    if(n==1){
        cout<<"0\n";
        return;
    }
    // int R=n;
    R[n+1]=n;
    for(int i=n;i>=1;i--){
        R[i]=R[i+1];
        while(R[i]>i&&a[R[i]]-a[i]>d){
            R[i]--;
        }
    }
    L[0]=1;
    for(int i=1;i<=n;i++){
        L[i]=L[i-1];
        while(L[i]<i&&a[i]-a[L[i]]>d){
            L[i]++;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i-1;j<=n;j++){
            dp[j]=sum[j]=f[j]=0;
        }
        for(int j=i,cnt=1;R[j]!=j;j=R[j]){
            for(int k=j+1;k<=R[j];k++){
                f[k]=j;
            }
        }
        dp[i]=sum[i]=1;
        for(int j=i+1;j<=n;j++){
            if(!f[j])break;
            dp[j]=sum[f[j]]-sum[max(L[j],i)-1];
            if(dp[j]>2)dp[j]=3;
            sum[j]=sum[j-1]+dp[j];
            // cout<<i<<" "<<j<<" "<<f[j]<<" "<<dp[j]<<"\n";
            if(dp[j]==2){
                // cout<<i<<" "<<j<<"\n";
                ans++;
            }
        }
    }
    cout<<ans<<"\n";
}
void solve2(){
    ans=0;
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==1){
        cout<<"0\n";
        return;
    }
    ll k=d/(a[2]-a[1]);
    if(k<=1){
        cout<<"0\n";
        return;
    }
    for(int i=1;i<=n;i++){
        if(i+k*2-1<=n)ans++;
    }
    cout<<ans<<"\n";
}
void solve3(){
    ans=0;
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        L[i]=R[i]=0;
        h[i]=0;
    }
    if(n==1){
        cout<<"0\n";
        return;
    }
    R[n+1]=n;
    for(int i=n;i>=1;i--){
        R[i]=R[i+1];
        while(R[i]>i&&a[R[i]]-a[i]>d){
            R[i]--;
        }
    }
    L[0]=1;
    for(int i=1;i<=n;i++){
        L[i]=L[i-1];
        while(L[i]<i&&a[i]-a[L[i]]>d){
            L[i]++;
        }
    }
    for(int i=n;i>=1;i--){
        ans+=h[R[i]-1];
        h[L[i]]++;
    }
    cout<<ans<<"\n";
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>C>>T;
    while(T--){
        if(1<=C&&C<=10)solve();
        else if(11<=C&&C<=12)solve2();
        else if(13<=C&&C<=14)solve3();
        else solve();
    }
    return 0;
}
/*
13 3
4 2
1 2 3 4
5 3
-2 -1 0 1 2
5 2
1 2 3 4 5

1
0
2
*/
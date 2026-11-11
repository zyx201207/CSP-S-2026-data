#include<bits/stdc++.h>
using namespace std;
const int N=2026,M=202026;
int dp[N][N],a[M],cnt[M];
int n,m;
int ss[50];
void soA(){
    int ans=0;
    for(int i=1;i<=n;i++) ans=max(ans,a[i]);
    cout<<ans;
    return ;
}
void soB(){
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j) ans=max(ans,a[i]&a[j]);
        }
    }
    cout<<ans;
    return ;
}
void soC(){
    int ans=a[1];
    for(int i=2;i<=n;i++){
        ans&=a[i];
    }
    cout<<ans;
    return ;
}
bool ck4(){
    for(int i=1;i<=n;i++){
            int cmp=a[i];
        while(cmp){
                if(cmp%2==0)return 0;
            cmp/=2;
        }
    }
    return 1;
}
void soD(){
    int mmin=99;
    for(int i=1;i<=n;i++){
        int cmp=a[i];
        while(cmp){
            cmp/=2;
            cnt[i]++;
        }
    }
    sort(cnt+1,cnt+n+1,greater<int>());
    for(int i=1;i<=m;i++) mmin=min(mmin,cnt[i]);
    int base=1;
    for(int i=1;i<=mmin;i++) base*=2;
    cout<<base-1;
    return ;
}
int ck5(){
    for(int i=1;i<=n;i++){
        if(a[i]>=4) return 0;
    }
    return 1;
}
void soE(){
    for(int i=1;i<=n;i++){
        ss[a[i]]++;
    }
    if(ss[3]>=m){cout<<3;return ;}
    if(ss[3]+ss[2]>=m) {cout<<2;return ;}
    if(ss[3]+ss[1]>=m) {cout<<1;return ;}
    cout<<0;
    return ;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    if(m==1){
        soA();
        return 0;
    }
    if(m==2){
        soB();
        return 0;
    }
    if(m==n){
        soC();
        return 0;
    }
    if(ck4()){
        soD();
        return 0;
    }
    if(ck5()){
        soE();
        return 0;
    }
    for(int i=1;i<=n;i++) dp[i][1]=a[i];
    for(int i=2;i<=n;i++){
        for(int k=1;k<i;k++){
        for(int j=1;j<=m;j++){
            dp[i][j]=max(dp[i][j],dp[k][j-1]&a[i]);
        }
    }
}
    cout<<dp[n][m];
    return 0;
}
 
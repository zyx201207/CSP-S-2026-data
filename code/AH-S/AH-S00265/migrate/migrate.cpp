#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int l_far[2000010],r_far[2000010];
int l_far_l[2000010],l_far_r[2000010],r_far_l[2000010],r_far_r[2000010];
long long pos[2000010];
int l_way_x[2000010],r_way_x[2000010],l_way_lr[2000010],r_way_lr[2000010];
long long l_dp[2000010],r_dp[2000010];
int n;
long long d;
void solve(){
    scanf("%d %lld",&n,&d);
    for(int i=1;i<=n;i++){
        scanf("%lld",&pos[i]);
        l_far_l[i]=0x3f3f3f3f;
        l_far_r[i]=-0x3f3f3f3f;
        r_far_l[i]=0x3f3f3f3f;
        r_far_r[i]=-0x3f3f3f3f;
        l_way_x[i]=0;
        r_way_x[i]=0;
        l_way_lr[i]=0;
        r_way_lr[i]=0;
        l_dp[i]=0;
        r_dp[i]=0;
    }
    int l_pre=1;
    for(int i=1;i<=n;i++){
        while(pos[i]-pos[l_pre]>d){
            l_pre++;
        }
        l_far[i]=l_pre;
        l_far_l[l_pre]=min(l_far_l[l_pre],i);
        l_far_r[l_pre]=max(l_far_r[l_pre],i);
    }
    int r_pre=n;
    for(int i=n;i>=1;i--){
        while(pos[r_pre]-pos[i]>d){
            r_pre--;
        }
        r_far[i]=r_pre;
        r_far_l[r_pre]=min(r_far_l[r_pre],i);
        r_far_r[r_pre]=max(r_far_r[r_pre],i);
    }
    for(int i=1;i<=n;i++){
        int L=1,R=i-1;
        L=max(L,r_far_l[i]);
        R=min(R,r_far_r[i]);
        L=max(L,l_far[i]);
        if(L<=R){
            l_way_x[i]=R-L+1;
        }
        else{
            l_way_x[i]=0;
        }
    }
    for(int i=1;i<=n;i++){
        int L=i+1,R=n;
        L=max(L,l_far_l[i]);
        R=min(R,l_far_r[i]);
        R=min(R,r_far[i]);
        if(L<=R){
            r_way_x[i]=R-L+1;
        }
        else{
            r_way_x[i]=0;
        }
    }
    for(int i=1;i<n;i++){
        int L=1,R=i-1;
        L=max(L,r_far_l[i+1]);
        R=min(R,r_far_r[i+1]);
        L=max(L,l_far[i]);
        if(L<=R){
            l_way_lr[i]=R-L+1;
        }
        else{
            l_way_lr[i]=0;
        }
    }
    for(int i=1;i<n;i++){
        int L=i+2,R=n;
        L=max(L,l_far_l[i]);
        R=min(R,l_far_r[i]);
        R=min(R,r_far[i+1]);
        if(L<=R){
            r_way_lr[i]=R-L+1;
        }
        else{
            r_way_lr[i]=0;
        }
    }
    for(int i=1;i<=n;i++){
        l_dp[i]=l_way_x[i];
        if(l_far[i]!=i  &&  r_far[l_far[i]]==i){
            l_dp[i]+=l_dp[l_far[i]];
        }
    }
    for(int i=n;i>=1;i--){
        r_dp[i]=r_way_x[i];
        if(r_far[i]!=i  &&  l_far[r_far[i]]==i){
            r_dp[i]+=r_dp[r_far[i]];
        }
    }
    long long ans=0;
    for(int x=1;x<n;x++){
        long long cnt_l=l_way_lr[x],cnt_r=r_way_lr[x];
        int pos_l=l_far[x];
        if(pos_l!=x  &&  r_far[pos_l]==x+1){
            cnt_l+=l_dp[pos_l];
        }
        int pos_r=r_far[x+1];
        if(pos_r!=x+1  &&  l_far[pos_r]==x){
            cnt_r+=r_dp[pos_r];
        }
        ans+=cnt_l*cnt_r;
    }
    printf("%lld\n",ans);
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    scanf("%d %d",&c,&T);
    while(T--){
        solve();
    }
    return 0;
}
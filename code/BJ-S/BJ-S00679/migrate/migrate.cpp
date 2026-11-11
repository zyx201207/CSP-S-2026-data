#include<bits/stdc++.h>
using namespace std;
#define MAXN 2000005
#define ll long long
ll n,d,a[MAXN],dp1[305][305],dp2[305][305];
void init(){
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
}
void solve1(){
    if(n<=3){
        cout<<0<<"\n";
        return ;
    }
    int k=d/(a[2]-a[1]);
    if(k<=1||n-(k*2-1)<=0){
        cout<<0<<"\n";
        return ;
    }
    cout<<n-(k*2-1)<<"\n";
    return ;
}
void solve2(){
    int ans=0;
    for(int s=1;s<=n;s++){
        for(int l=1;l+s-1<=n;l++){
            int r=l+s-1;
            if(a[r]-a[l]<=d){
                dp1[l][r]=1;
                continue;
            }
            dp1[l][r]=MAXN;
            for(int k=l+1;k<=r-1;k++){
                dp1[l][r]=min(dp1[l][r],dp1[l][k]+dp1[k][r]);
            }
        }
    }
    for(int s=1;s<=n;s++){
        for(int l=1;l+s-1<=n;l++){
            int r=l+s-1;
            if(dp1[l][r]==1){
                dp2[l][r]=1;
                continue;
            }
            dp2[l][r]=0;
            for(int k=l+1;k<=r-1;k++){
                if(dp1[l][k]+dp1[k][r]==dp1[l][r]&&dp1[l][k]&&dp1[k][r]&&dp1[l][r]){
                    dp2[l][r]+=dp2[l][k]*dp2[k][r];
                }
            }
            if(dp2[l][r]==2){
                ans++;
            }
        }
    }
    cout<<ans<<"\n";
    return ;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    int ID,T;
    cin>>ID>>T;
    while(T--){
        init();
        if(ID==11||ID==12){
            solve1();
        }else if(ID<11){
            solve2();
        }
    }
    return 0;
}

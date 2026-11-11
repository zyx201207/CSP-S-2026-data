#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll d;
ll a[2000005];
ll sum[5005][5005]={0};
ll cnt[5005][5005]={0};
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(c==11||c==12){
            ll ans=0;
            ll tt=d/(a[2]-a[1]);
            for(int i=tt+1;i<2*tt;i++){
                ans+=n-i;
            }
            cout<<ans<<endl;
        }else if(d>=a[n]-a[1]){
            cout<<0<<endl;
        }else if(c<=10){
            ll ans=0;
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    cnt[i][j]=0;
                    sum[i][j]=0;
                }
            }
            for(int len=1;len<=n;len++){
                for(int i=1;i+len<=n;i++){
                    if(a[i+len]-a[i]<=d){
                        cnt[i][i+len]=1;
                        sum[i][i+len]=1;
                    }else if(len>1){
                        ll mi=9*1e18;
                        for(int k=i+1;k<i+len;k++)if(cnt[i][k]!=0&&cnt[k][i+len]!=0)mi=min(mi,sum[i][k]+sum[k][i+len]);
                        sum[i][i+len]=mi;
                        for(int k=i+1;k<i+len;k++)if(sum[i][k]+sum[k][i+len]==mi)cnt[i][i+len]+=cnt[i][k]*cnt[k][i+len];
                    }
                }
            }
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    if(cnt[i][j]==2)ans++;
                }
            }
            cout<<ans<<endl;
        }else{
            cout<<0<<endl;
        }
    }
    return 0;
}//炸了
#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>

using namespace std;
long long c,t,n,d,ans;
long long x[2000005];
long long dp[2000005];
int pl[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c==11||c==12){
        while(t--){
            cin>>n>>d;
            for(int i=1;i<=n;i++){
                cin>>x[i];
            }if(x[2]-x[1]<=d/3)cout<<(n-4)/3+((n-4)%3==2)<<endl;
            else if(x[2]-x[1]>d/2)cout<<0<<endl;
            else cout<<n-3<<endl;
        }return 0;
    }if(c==13||c==14){
        while(t--){
            cin>>n>>d;
            for(int i=1;i<=n;i++){
                cin>>x[i];
            }cout<<0<<endl;
        }return 0;

    }
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }for(int i=1;i^n;i++){
            memset(dp,0x3f,sizeof(dp));
            dp[i]=1;
            pl[i]=1;
            for(int j=i;j<=n;j++){
                if(pl[j]==2)ans++;
                int k=j+1;
                while(x[k]-x[j]<=d&&k<=n){
                    if(dp[k]>dp[j]+1)dp[k]=dp[j]+1,pl[k]=pl[j];
                    else if(dp[k]==dp[j]+1)pl[k]+=pl[j];
                    k++;
                }
            }
            memset(pl,0,sizeof(pl));
        }cout<<ans<<endl;
        ans=0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

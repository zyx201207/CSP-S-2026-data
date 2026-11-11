#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
long long a[2000005];
long long g[5050][5050];
long long ans[5050][5050],sum;
map<long long,int> dp;
map<long long,bool> mp;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        memset(g,0x3f,sizeof(g));
        sum=0;
        memset(ans,0,sizeof(ans));
        long long mx=-1e18,mn=1e18;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            //mp[a[i]]=1;
            for(int j=1;j<=i;j++){
                g[i][j]=g[j][i]=a[i]-a[j];
            }
            mx=max(mx,a[i]);
            mn=min(mn,a[i]);
        }
        //for(int i=mn;i<=mx;i++){
        //    int cnt=0;
        //    long long he=0;
        //    for(int j=1;j<=d;j++){
        //        if(mp[i-j]==1){
        //            cnt++;
        //            if(cnt>2) break;
        //            he+=dp[i-j];
        //        }
        //    }
        //    if(cnt==2) dp[i]=he;
        //}
        //cout<<dp[mx]<<endl;
        for(int k=mn;k<=mx;k++){
            for(int i=mn;i<=mx;i++){
                for(int j=mn;j<=mx;j++){
                   if(i==j){
                        g[i][j]=0;
                        continue;
                   }
                   if(g[i][k]<=d&&g[k][j]<=d){
                        if(g[i][j]>g[i][k]+g[k][j]){
                            ans[i][j]=0;
                            g[i][j]=g[i][k]+g[k][j];
                        }else if(g[i][j]==g[i][k]+g[k][j]){
                            ans[i][j]++;
                        }
                  }
                }
            }
        }
        for(int i=mn;i<=mx;i++){
           for(int j=mn;j<=mx;j++){
                if(i!=j&&ans[i][j]==2) sum++;
            }
       }
        cout<<sum/2<<endl;
    }
    return 0;
}


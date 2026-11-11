#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int a[2000010];
int ac[2000010];
int dp[2000010];
int mod=0x3f3f3f3f;
int jy[2000010];
/*int bj(int d){
    if(jy[d]!=-1){
        return jy[d];
    }else{
        jy[d]=0;
        for(int i=1;i<=n;i++){
            jy[d]+=jy[i]
        }
        return jy[d]
    }
}*/
int ss(int a[],int n){
    memset(dp,0,sizeof(dp));
    int cnt=0;
    dp[1]=1;
        for(int i=2;i<=n;i++){
            //cout<<i<<"\n";
            for(int j=i-1;j>=1;j--){
                //cout<<a[i]-a[j]<<"\n";
                if(a[i]-a[j]<=d){
                    //cout<<"j"<<j<<"dp[j]"<<dp[j]<<"\n";
                    dp[i]+=dp[j];
                }
            }
            if(dp[i]==2){
                cnt++;
            }
        }

    return cnt;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        memset(a,0,sizeof(a));
        memset(dp,0,sizeof(dp));
        cin>>n>>d;

        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                //int ac[2000010]
                memset(ac,0,sizeof(ac));
                for(int k=j;k<=i;k++){
                    ac[k-j+1]=a[k];
                }
                ans+=ss(ac,i-j+1);
                /*for(int k=1;k<=i-j+1;k++){
                    cout<<ac[k];
                }*/
                //cout<<" "<<i-j+1<<"\n";
                //ans+=ss(ac,i-j+1);
            }
        }

        //cout<<ss(a,n);
        cout<<ans;
        /*
        dp[1]=1;
        int cnt=0;
        for(int i=2;i<=n;i++){
            //cout<<i<<"\n";
            for(int j=i-1;j>=1;j--){
                //cout<<a[i]-a[j]<<"\n";
                if(a[i]-a[j]<=d){
                    //cout<<"j"<<j<<"dp[j]"<<dp[j]<<"\n";
                    dp[i]+=dp[j];
                }
            }
            if(dp[i]==2){
                cnt++;
            }
        }
        */
        /*for(int i=1;i<=n;i++){
            cout<<dp[i];
        }*/
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
    cin>>c>>t;
    if(1<=c&&c<=10){
        while(t--){
            int n,d,ans=0;
            cin>>n>>d;
            int x[n+5],dp[n+5][n+5]={0};
            for(int i=1;i<=n;i++) cin>>x[i];
            for(int i=1;i<=n;i++) dp[i][i]=1;
            
            int l=1,r=1,sum=0,v[n+5];
            while(r<=n){
                sum+=x[r]-x[max(1,r-1)];
                while(sum>d) sum-=x[l+1]-x[l],l++;
                v[r]=l,r++;
            }
            
            for(int i=1;i<n;i++){
                for(int j=i+1;j<=n;j++){
                    for(int k=0;k<v[j].size();k++){
                        dp[i][j]+=dp[i][v[j][k]];
                        //cout<<i<<' '<<j<<' '<<k<<' '<<dp[i][k]<<'\n';
                    }
                }
            }

            for(int i=1;i<n;i++) for(int j=i+1;j<=n;j++){
                cout<<i<<' '<<j<<' '<<dp[i][j]<<'\n';
                if(dp[i][j]==2) ans++;
            }
            cout<<ans<<'\n';
        }
    }
    if(11<=c&&c<=12){
        while(t--){
            int n,d,ans=0;
            cin>>n>>d;
            int x[n+5]；
            for(int i=1;i<=n;i++) cin>>x[i];
            int a=x[2]-x[1],b=d/a;
            
        }
    }
    return 0;
}

//T2最短路模板不会写
//T3打部分分分吧
//不会打......TAT

//还有，为啥出题人这么喜欢图论啊
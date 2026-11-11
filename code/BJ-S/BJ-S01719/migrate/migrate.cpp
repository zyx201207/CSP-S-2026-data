#include <bits/stdc++.h>
using namespace std;
const int N=2*1e6+10;
int x[N];
int dp[N];
bool fa;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int cnt=0;
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }int q=x[2]-x[1];
        for(int i=3;i<=n;i++){
            if(x[i]-x[i-1]!=q){
                fa=1;
            }
        }
        if(fa==0){
            if(d%2!=0){
                cout<<0;
            }else{
                for(int i=1;i<=n;i++){
                    if(i+d<=n){
                        cnt++;
                    }else{
                        break;
                    }
                }cout<<cnt-1<<endl;
            }
        }else if(n<=300){
            dp[1]=0;
            dp[2]=x[2]-x[1];
            for(int i=1;i<=n;i++){
                for(int j=1;j<=d;j++){
                    if(i>j){
                        dp[i]+=dp[i-j];
                    }
                }
            }
            for(int i=1;i<=n;i++){
                for(int j=1;j<d;j++){
                    for(int k=j+1;k<=d;k++){
                        if(i>j&&i>k){
                            if(dp[i-j]==dp[i-k]){
                                cnt++;
                            }
                        }
                    }
                }
            }cout<<cnt<<endl;
        }else{
            cout<<0<<endl;
        }
    }
    return 0;
}

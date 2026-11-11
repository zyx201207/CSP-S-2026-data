#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int turm=1;turm<=t;turm++){
        int n;unsigned long long d;
        cin>>n>>d;
        vector<long long>x;
        vector<int>dp;
        x.push_back(0);
        dp.push_back(0);
        for(int i=1;i<=n;i++){
            long long tmpp;
            cin>>tmpp;
            x.push_back(tmpp);
            dp.push_back(0);
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(i==j){dp[j]=0;continue;}
                int tmp=INT_MAX,tmp2=0,tmp3=0,k;
                for(k=j-1;k>=i;k--){
                    if(d>=(x[j]-x[k])){
                        tmp=min(tmp,dp[k]+1);
                        tmp3=dp[k];
                    }else{
                        break;
                    }
                }
                k++;
                for(;k<=j-1&&(dp[k]==tmp3);k++){
                    tmp2++;
                }
                dp[j]=tmp;
                if(tmp2==2){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

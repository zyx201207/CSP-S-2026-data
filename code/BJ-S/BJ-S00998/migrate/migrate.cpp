#include <bits/stdc++.h>
using namespace std;
int C,T;
int res;
int n,d;
int a[200010];
int dp[200010],dp_min_word[200010];
bool big_or_small(int i,int j){
     if((a[i]-a[j])<d)return true;
     return false;
}
int main(){
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
    cin>>C>>T;
    while(T--){
    res=0;
        cin>>n>>d;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
     for(int tt=0;tt<n-3;tt++){
                memset(dp,-1,sizeof dp);
    memset(dp_min_word,0x3f,sizeof dp_min_word)
        if(a[tt]<0){
            for(int i=tt;i<n;i++){
                a[i]+=(0-a[tt])
                dp[a[i]]++;
            }
        }
        dp[a[tt]]=1;
        dp_min_word[a[0]]=0;
        if(a[tt+1]-a[tt]>d){
            continue;
        }else{
           dp[a[tt+1]]=1;
           dp[a[tt+1]]=1;
        }
        for(int i=tt+2;i<n;i++){
            for(int k=1;k<=d;k++){
                if(i-k>=tt&&dp[i-k]!=-1&&big_or_small(i,i-k)){
                if(dp_min_word[a[i]]>dp_min-word[a[i-k]]+1){
                    dp[a[i]]=1,dp_min_word[a[i]]=dp_min_word[a[i-k]]+1;
                }else if(dp_min_word[a[i]]=dp_min-word[a[i-k]]+1){
                    dp[a[i]]++;
                }
            }
            }
        }
        for(int i=tt+2;i<n;i++){
            if(dp[a[i]]==2)res++;
        }
     }
     cout<<res<<endl;
    }
    return 0;
}

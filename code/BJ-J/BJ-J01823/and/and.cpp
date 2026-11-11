#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005];
long long dp[40];
vector<long long> num;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++) {
        long long a;
        cin>>a;
        num.push_back(a);
    }
    dp[0]=1;
    for(long long i=1;i<=32;i++) dp[i]=dp[i-1]*2;
    long long ans=0;
    //cout<<(3&dp[32])<<endl;
    for(long long i=32;i>=0;i--){
        //cout<<dp[i]<<endl;
        vector<long long> num_;
        num_.clear();
        long long cnt=0;
        for(long long j=0;j<num.size();j++){
            if((num[j]&dp[i])==dp[i]){
                //cout<<num[j]<<" ";
                cnt++;
                num_.push_back(num[j]);
            }
        }
        //cout<<endl;
        if(cnt>=m){
            ans+=dp[i];
            num=num_;
        }
    }
    cout<<ans;
    return 0;
}

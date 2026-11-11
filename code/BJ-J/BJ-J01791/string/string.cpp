#include<bits/stdc++.h>
using namespace std;
char c;
long long x[200005],n,dp[1005][1005],l;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>c;
        for(int j=1;j<=x[i];j++)s+=c;
    }
    l=s.size();
    for(int i=0;i<l;i++){
        for(int j=i;j<l;j++){
            if(i==j)dp[i][j]=0;
            else dp[i][j]=INT_MAX;
        }
    }
    /*for(int i=0;i<l;i++){
        for(int j=i;j<l;j++){
            cout<<dp[i][j]<<" ";
        }cout<<endl;
    }*/
    for(int len=0;len<l;len++){
        for(int i=0;i+len<l;i++){
            int j=len+i;
            if(s[i]==s[j])dp[i][j]=min(dp[i][j],dp[i+1][j-1]);
            else dp[i][j]=min(dp[i][j],dp[i+1][j-1]+1);
        }
    }
    cout<<dp[0][l-1];
    return 0;
}

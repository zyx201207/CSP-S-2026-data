#include <bits/stdc++.h>
using namespace std;
int n,a,dp[2000][2000];
char c;
string s,rs;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        s=s+string(a,c);
    }
    rs=s;
    reverse(rs.begin(),rs.end());
    for(int j=0;j<s.size();j++){
        dp[0][j]=s[0]==rs[j];
    }
    for(int i=1;i<s.size();i++){
        for(int j=0;j<s.size();j++){
            if(s[i]==rs[j])
                dp[i][j]=max(dp[i][j-1],dp[i-1][j-1])+1;
            else
                dp[i][j]=max(dp[i][j-1],dp[i-1][j-1]);
        }
    }
    /*for(int i=0;i<s.size();i++){
        for(int j=0;j<s.size();j++)
            cout<<dp[i][j];
        cout<<endl;
    }*/
    cout<<s.size()-dp[s.size()-1][s.size()-1];
    return 0;
}
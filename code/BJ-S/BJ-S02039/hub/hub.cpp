#include <bits/stdc++.h>
using namespace std;
int a[2000005][3];int dp[2000005];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        int n,k;
        cin>>n>>k;
        for(int j=1;j<=n;j++){
            cin>>a[j][1]>>a[j][2];
        }
        for(int j=1;j<=n;j++){
            queue<int> q;q.push(j);int e=0;
            while(!q.empty()){
                i++;
                for(int r=1;r<=n;r++){
                    if(a[r][1]==q.front()){
                        dp[a[r][2]]=max(dp[a[r][2]],i);
                    }
                    if(a[r][2]==q.front()){
                        dp[a[r][1]]=max(dp[a[r][1]],i);
                    }
                }
                q.pop();
            }
        }int ans=0;
        for(int j=1;j<=n;j++){
            ans=min(ans,dp[j]);
        }
        cout<<ans-1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

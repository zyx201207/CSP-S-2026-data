#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],dp[N],dp2[N],s[N],ans[N],s1[N],lt[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)lt[a[i]]=i;
    for(int i=1;i<=n;i++){
        s[i-1]-=s1[a[i]];
        dp2[i]=s[i-1];
        dp[i]=(lt[a[i]]==i?0:i-dp2[i]);
        s[i]=s[i-1]+dp[i];
        s1[a[i]]=dp[i];
        ans[a[i]]+=i-dp[i]-dp2[i];
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}




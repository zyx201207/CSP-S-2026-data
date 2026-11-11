#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6;

ll dp[N];
ll a[N];
ll n,m;
ll last[N];
//ll lazy[N];
ll s[N];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        s[i]=1;
        //dp[i]=i;
        cin>>a[i];
        last[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1]+s[i];
        //for(int j=1;j<=m;j++){
        //    if(i<last[j]) dp[i]-=lazy[j];
        //}
        if(i==last[a[i]]) continue;
        //lazy[a[i]]+=dp[i];
        s[i]-=dp[i];
        s[last[a[i]]]+=dp[i];
        dp[i]=dp[i-1]+s[i];
        //dp[i]=0;
    }
    //cout<<"last:"
    //for(int i=1;i<=m;i++){
    //    cout<<last[i]<<' ';
    //}
    //cout<<"dp:";
    for(int i=1;i<=m;i++){
        cout<<dp[last[i]]<<' ';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

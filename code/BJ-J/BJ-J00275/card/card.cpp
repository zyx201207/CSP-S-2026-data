#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5,MAXM=3e5+5;
int n,m,a[MAXN];
int lst[MAXM],dp[MAXM];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        lst[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        if(lst[a[i-1]]==i-1){
            dp[a[i]]+=dp[a[i-1]];
        }
        dp[a[i]]++;
    }
    for(int i=1;i<=m;i++){
        cout<<dp[i]<<' ';
    }
    return 0;
}

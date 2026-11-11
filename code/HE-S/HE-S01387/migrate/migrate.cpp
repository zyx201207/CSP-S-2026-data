#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t,x[10005],n[10005],d[10005],dp[10005],cnt[10005]={};
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n[i]>>d[i];
        for(int j=1;j<=n[i];j++){
            cin>>x[j];
            if(j%d[i]==1){
                cnt[i]++;
            }
        }
    }
    for(int i=1;i<=t;i++){

        cout<<cnt[i]-1<<endl;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=1000000;
long long c,t,n,d,x[N],dp[N];
long long fin(long long k){
    long long ans=0;
    for(int i=k-1;i>=1;i--){
        if(x[k]-x[i]>d)
            return ans;
            ans+=dp[i];
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>t;
    while(t--){
        long long sum=0;
        cin>>n>>d;
        if(n<=5000){
            for(int i=1;i<=n;i++){
                cin>>x[i];
                dp[i]=0;
            }
            for(int p=1;p<=n;p++){
                dp[p]=1;
                for(int i=p+1;i<=n;i++){
                    dp[i]=fin(i);
                    if(dp[i]==2){
                        sum++;
                    }
                }
                dp[p]=0;
            }
            cout<<sum<<endl;
        }
        else {
            for(int i=1;i<=n;i++){
                cin>>x[i];
            }
            if(d>=2*max(x[2]-x[1],x[1]-x[2])){
                cout<<n-2<<endl;
            }
            else cout<<"0"<<endl;
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=2e6;
long long c,t,n,m,dp[N],a[N],ans;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        ans=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int l=a[2]-a[1];
        int num=m/l;
        if(num==2){
            cout<<(n-num*2+1)*(num-1)<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
int n,m,a,sum[1005],ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a;
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+i;
        if(sum[i]>m){
            ans=i-1;
            break;
        }
    }
    cout<<ans;
}
//A
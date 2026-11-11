#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define N 500005
LL n,m,ans;
LL nums[N],pre[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(LL i=1;i<=n;i++){
        cin>>nums[i];
    }
    sort(nums+1,nums+n+1);
    for(LL i=1;i<=n;i++){
        pre[i]=nums[i]+pre[i-1];
    }
    for(LL i=1,j=1;i<=n&&j<=i;){
        LL d=i-j+1;
        LL cost=nums[i]*d-(pre[i]-pre[j-1]);
        if(cost<=m){
            ans=max(ans,d);
        }
        if(cost<=m){
            i++;
        }
        if(cost>m){
            j++;
        }
    }
    cout<<ans;
    return 0;
}

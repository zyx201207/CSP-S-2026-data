#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+10,M=1e12+10,Z=1e7+10;
ll n,a[N],m,ans,dp[N],res,minn=M,maxn=-M;

int main(){
   freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ans+=a[i];
        minn=min(minn,a[i]);
        maxn=max(maxn,a[i]);
    }
    if(m==0){
        cout<<0;
        return 0;
    }
    sort(a+1,a+n+1);
    if(maxn*n<=Z){
        for(int i=minn;i<=maxn;i++){
        ll cnt=0;
        ans=0;
        for(int j=n;j>=1;j--){
            ans+=max((ll)0,i-a[j]);
            if(i-a[j]>=0){
                cnt++;
            }
        }
        if(ans<=m){
            res=max(res,cnt);
        }
    //    cout<<cnt<<" "<<i<<" "<<(ans)<<endl;
    }
    cout<<res;
    }else{
        ll y=0;
        for(int i=2;i<=n;i++){
            if(i==2){


                   y=a[2]-a[1];
            }

            if(a[i]-a[i-1]!=y){
                return 0;
            }
        }
        if(y==0) cout<<n;
        else if(m<y) cout<<1;
        else cout<<m/y+1;
    }

    return 0;
}

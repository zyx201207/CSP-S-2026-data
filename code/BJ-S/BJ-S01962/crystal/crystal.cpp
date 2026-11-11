#include <bits/stdc++.h>
using namespace std;
long long n,m,a[50005],maxn=-0x3f3f3f,minn=0x3f3f3f;
int main(){
    freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
        minn=min(minn,a[i]);
    }
    //cout<<maxn<<minn<<endl;
    sort(a+1,a+n+1);
    long long sum=0,cnt=0,ans=-0x3f3f3f;
    for(int k=maxn;k>=minn;k--){
        long long b[50005];
        sum=0;cnt=0;
        for(int i=n;i>=1;i--){
            b[i]=k-a[i];
            //cout<<b[i]<<" ";
            if(b[i]>=0 && (sum+b[i])<=m){
                sum+=b[i];
                cnt++;
            }
            //cout<<sum<<" "<<cnt<<" ";
        }
        ans=max(ans,cnt);
        //cout<<endl<<k<<" "<<sum<<" "<<cnt<<endl;
    }
    cout<<ans;
    return 0;
}
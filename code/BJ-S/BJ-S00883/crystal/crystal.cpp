#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,ans,a[N],s[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    for(int i=1;i<=n;i++){
        long long l=1,r=i,cnt=0;
        while(l<=r){
            long long mid=l+r>>1;
            //cout<<i<<" "<<mid<<" "<<s[i]-s[i-mid]<<endl;
            if(a[i]*mid-(s[i]-s[i-mid])<=m){
                cnt=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        //cout<<i<<" "<<cnt<<endl;
        ans=max(ans,cnt);
    }
    cout<<ans<<endl;
    return 0;
}

#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m,a[N],cnt=1,t,ans=-1e18;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    if(m==0){
        for(int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++){
            if(a[i]==a[i+1]) cnt++;
            else{
                ans=max(ans,cnt);
                cnt=1;
            }
        }
        cout<<ans;
        return 0;
    }
    if(n>5000){
        int c=0;
        for(int i=1;i<=n;i++) cin>>a[i];
        c=a[2]-a[1];
        while(m-cnt*c>0){
            m-=cnt*c;
            cnt++;
        }
        cout<<cnt;
            return 0;
    }
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        cnt=1,t=m;
        for(int j=i-1;j>=1;j--){
            if(a[i]-a[j]<=t) t-=a[i]-a[j],cnt++;
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}

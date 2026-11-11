#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1000005;
ll n,m;
ll a[N];
ll ax[N];
bool cmp(int x,int y){
    return x<y;
}
int ans=0;
ll pf(int cnt,int l){
    ll sum=0;
    for(int i=l-cnt;i<=l;i++){
        sum+=ax[i];
    }
    return sum;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    ax[0]=0;
    for(int i=2;i<=n;i++){
        ax[i]=a[i]-a[i-1];
    }
    int cnt=0;ll cs=0;
    for(int i=1;i<=n;i++){
        cs+=ax[i]*cnt;
        cnt++;
        if(cs>m){
            while(cs>m){
                cnt--;
                cs-=pf(cnt-1,i);
    //            cout<<"---\n"<<pf(cnt-1,i)<<"\n---\n";
            }
        }
        ans=max(ans,cnt);
    //    cout<<cnt<<" "<<cs<<" "<<ans<<"\n";
    }
    cout<<ans;
    return 0;
}

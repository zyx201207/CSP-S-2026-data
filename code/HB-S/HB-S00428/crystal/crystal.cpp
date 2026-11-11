#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],ans=0,cf[500005],cnt=1,k=0,sum=0,fr=1;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(ll i=1;i<=n-1;i++){
        cf[i]=a[i+1]-a[i];
    }
    for(ll i=1;i<=n-1;i++){
        k+=cf[i];
        sum+=cf[i]*cnt;
        cnt++;
        while(sum>m){
            cnt--;
            sum-=k;
            k-=cf[fr];
            fr++;
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}

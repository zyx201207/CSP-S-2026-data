#include<bits/stdc++.h>
using namespace std;


#define ll long long
const ll N=5e5+10;
ll n,m,a[N],b[N];
int ans=0;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) b[i]=a[i]-a[i-1];

    int l=1,r=1,cnt=0;
    ll sum=0;
    while(r<=n){
        if(sum<=m){
            ans=max(ans,cnt+1);
            r++;
            sum+=b[r]*(++cnt);
        }
        if(sum>m){
            sum-=(a[r]-a[l]);
            l++;
            cnt--;
        }
    }
    cout<<ans;

    return 0;
}

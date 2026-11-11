#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll t[505],a[500005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    ll i=1,j=1;
    ll sum=0,ans=1,cnt=0,t=0;
    while(j<=n){
        if(sum>m){
            i++;
            ans--;
            sum-=(a[j]-a[i-1]);
            cnt--;
        }else{
            t=max(t,ans);
            j++;
            ans++;
            cnt++;
            sum+=(a[j]-a[j-1])*cnt;
        }
    }
    cout<<t;
    return 0;
}


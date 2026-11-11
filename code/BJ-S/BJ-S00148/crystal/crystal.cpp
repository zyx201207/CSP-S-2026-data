#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb emplace_back
#define mid ((l+r)>>1)
#define pii pair<int,int>
#define fi first
#define se second
const int N=5e5+5;
int n;
ll a[N],m;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int ans=1,la=1;
    ll sum=0;
    for(int i=1;i<=n;i++){
        sum+=(ll)(a[i]-a[i-1])*(i-la);
        while(sum>m){
            sum-=a[i]-a[la];
            la++;
        }
        ans=max(ans,i-la+1);
    }
    cout<<ans;
    return 0;
}
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
int ans=0;
ll cnt=0;
ll a[500010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1,j=1;i<=n;i++){
        cnt+=(i-j)*(a[i]-a[i-1]);
        while(i>j&&cnt>m){
            cnt-=a[i]-a[j];
            j++;
        }
        ans=max(ans,i-j+1);
    }
    cout<<ans;
    return 0;
}
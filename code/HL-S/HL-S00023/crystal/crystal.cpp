#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int n,ans=1;
ll m,rest;
ll a[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    rest=m;
    int l=1;
    for(int r=2;r<=n;r++){
        rest-=(r-l)*(a[r]-a[r-1]);
        while(rest<0)rest+=a[r]-a[l++];
        ans=max(ans,r-l+1);
    }cout<<ans;
    return 0;
}

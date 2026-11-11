#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;

typedef long long ll;
ll n,m,ans=-0x3f3f3f3f3f3f3f3f;
ll a[200005],dp[200005][200005];
bool pow1(ll a,ll b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,pow1);
    ans=a[i];
    for(int i=1;i<=m;i++){
        ans=ans & a[i];
    }
    cout<<ans;
    return 0;
}


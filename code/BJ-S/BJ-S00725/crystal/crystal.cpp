/*
这题想不出来有什么迷惑行为了，不如屏幕前的你帮我编几个吧（
*/
#include<bits/stdc++.h>
using namespace std;
constexpr int N=500005;
int n,ans;
long long m,sum,a[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=n,j=n;i;i--){
        sum+=(i-j)*(a[i]-a[i+1]);
        while(j&&sum+a[i]-a[j]<=m)sum+=a[i]-a[j--];
        ans=max(ans,i-j);
    }
    cout<<ans;
    return 0;
}
/*
666 卡 T1 上了.
不是到底为啥多 1 啊???
卡了卡了.
*/
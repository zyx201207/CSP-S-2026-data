#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,ans;
ll a[1919810];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    ll l=1,r=1;
    ll sum=0;
    for(;l<=r&&r+1<=n;){
        if(sum+(a[r+1]-a[r])*(r-l+1)<=m&&r+1<=n){
            sum+=(a[r+1]-a[r])*(r-l+1);
            r++;
        }
        else if(a[r]-a[l]>=(a[r+1]-a[r])*(r-l)&&sum-(a[r]-a[l])+(a[r+1]-a[r])*(r-l)>=0&&r+1<=n){
            sum-=a[r]-a[l];
            sum+=(a[r+1]-a[r])*(r-l);
            l++;
            r++;
        }
        else if(sum-(a[r]-a[l])+(a[r+1]-a[r])*(r-l)>=0){
            sum-=a[r]-a[l];
            l++;
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}
/*
14：41秒掉T1
有种不祥的预感

oh no！我发现我貌似不能用signed main，而且要有return 0！！！
这两个我在考-J的时候都没写呜呜呜

洛谷关注uid1063830谢谢喵

ok，我的正解炸了，然后我用二分的写法跟我的正解打对拍发现我的正解错了，我的二分写法应该是没问题的，而且二分的时间复杂度正确。

17：02分，抱歉，是我的二分写错了，继续用上面那份代码继续打对拍！！！

17：10分，拍了1000组没问题，应该过了
*/
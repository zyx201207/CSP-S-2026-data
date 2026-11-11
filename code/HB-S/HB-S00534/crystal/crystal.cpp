#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define mid (l+r)/2
using namespace std;
const int N=5e5+5;
int n,ans;
ll a[N],m,diff[N],pred[N],prepred[N];
inline bool check(int k,int n){
    return (k-n)*pred[k]-prepred[k-1]+prepred[n-1]<=m?1:0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        diff[i]=a[i]-a[i-1];
        pred[i]=diff[i]+pred[i-1];
        prepred[i]=pred[i]+prepred[i-1];
    }
    for(int i=n;i>=1;i--){
        int l=1,r=i;
        while(l<r){
            if(check(i,mid)) r=mid;
            else l=mid+1;
        }
        //这里用二分
        ans=max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}
//海螺姑娘开局一技能加普攻切换形态，二技能搭的士，对面替身就反手熊猫，你个东子。
//小鸣佐开局蛤蟆接换形态，佐助直接雷切上墙蓄力，全x全y你拿头打，东子。
//百虎开局全x火，躲了我就土流枪再起手，直接反手镰鼬，嘶咬你，东子。
//老佩开局土流枪接吸，虽然有后摇但我们是老忍者，硬体时间长，可以按出熊猫，直接走你脸上a，a完一套直接一技能戏卡你a三下二技能灌伤，说实话很难应对我的墙角奥义，对吧东子？

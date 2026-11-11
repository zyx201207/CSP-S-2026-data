/*
jn（用于复制）
究竟是什么样的人拼出了我的键盘：
Esc F1 F2 F3 F4 F5 F6 ScrollLock PauseBreak F9 F10 F11 F12 PrtScnSysRq NumLock /
~ 1 2 3 4 5 6 7 8 9 0 - = Backspace Insert Home PgUp （无） （无） * -
Tab Q W E R T Y N I O P { } | Delete End PgDn 7 8 9 +
CapsLock M A D F G H F8 K L : " Shift 4 5 6 
Enter Z X C V B J F7 < > ? Shift 上箭头 1 2 3 Enter
Ctrl Alt Windows 空格 Alt Windows （方块） Ctrl 左箭头 下箭头 右箭头 0 . 
S和U还被吃了
你考我背键盘就算了，关键是现在n和j我按都按不下去，一按下去就卡住然后出来一大堆
求上迷惑行为大赏
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500000;//5e5
int n;//5e5
ll m;//1e18
ll a[N+10],s[N+10];//1e12 5e17
bool check(int x){
    for(int i=x;i<=n;i++)
        if((x-1)*a[i]-(s[i-1]-s[i-x])<=m)
            return true;
    return false;
}
int bs(int l,int r){
    while(l<r){
        int mid=(l+r+1)/2;//5e5
        if(check(mid))l=mid;
        else r=mid-1;
    }
    return l;
}
int main(){
    // freopen("crystal4.in","r",stdin);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    cout<<bs(1,n);
    return 0;
}
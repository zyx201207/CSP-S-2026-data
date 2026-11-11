#include <bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int j = 29;j >= 0;j--){
        int cnt = 0;
        for (int i = 1;i <= n;i++){
            if (a[i] & (1 << j)) {
                swap(a[i],a[cnt + 1]);
                cnt++;
            }
        }
        if (cnt >= m) n = cnt;
    }
    int ans = -1;
    for (int i = 1;i <= m;i++) ans &= a[i];
    cout << ans << endl;
    return 0;
}
/*
考号恰好是能看作二进制数的，今天又有二进制，真是幸运。

//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
freopen("travel.in","w",stdin);
freopen("travel.out","r",stdout);
freopen("travel,in"."w".stdout);
freopen("travel,out"."r".stdin);

三年以来，我从未拿过CSP-J一级证。第一次是23年T2想了贪心不会做，T3看到是大模拟心生恐慌；第二次是初赛差一分进去；第三年是轻视T2被一拳薄纱70%。
今天，我要拿回本应属于我的【不知道该说啥】！顺便说一句，万圣节快乐！
*/

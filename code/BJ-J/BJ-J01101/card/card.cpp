#include <bits/stdc++.h>
using namespace std;
int a[500005]
int dp[5005][3005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int turn = n;turn >= 1;turn--){
        int pos = 0;
        for (int i = n;i >= turn;i--){
            if (a[i] == a[turn]){
                pos = i + 1;
                break;
            }
        }
        for (int i = 1;i <= m;i++) dp[turn][i] = dp[pos][i];
        dp[turn][a[turn]]++;
    }
    for (int i = 1;i <= m;i++) {
        int ans = 0;
        for (int j = 1;j <= n;j++) ans += dp[j][i];
        cout << ans <<" ";
    }
    cout << endl;
    return 0;
}
/*
在我们那，这个游戏叫猴拉车，但不同的是打出的那张在收牌后也会一并收走

//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
freopen("travel.in","w",stdin);
freopen("travel.out","r",stdout);
freopen("travel,in"."w".stdout);
freopen("travel,out"."r".stdin);

我是BJ-S01019!
luogu uid = 857437!
全谷最弱红名，连这题都不会的那种！


3 [1 [2  1] 3][2  3] 1 [2  1]

   1 [2  1][3 [2  3] 1][2  1]

      2 [1  3  2][3  1  2] 1

         1 [3 [2  3] 1][2  1]

            3 [2  3] 1 [2  1]

               2 [3  1  2] 1

                  3  1 [2  1]

                     1 [2  1]

                        2  1

                           1

1h30min，已经是极限了，此时是100+100+100+48=348 approx。
现在没什么脑子了，打算歇一会写对拍。


对拍都懒得写，于是写了个家乡猴拉车自动机，放在下面。
queue<int>q;
int a[500005];
void print(int cnt){
    for (int i = 1;i <= cnt;i++) cout << a[i] << " ";
    cout << endl;
}
void print(queue<int>q){
    queue<int>tmp;
    cout << "handcards: ";
    while(!q.empty()) {
        cout << q.front() << " ";
        tmp.push(q.front());
        q.pop();
    }
    cout << endl;
    q = tmp;
}
void monkeycart(){
    freopen("monkeycart.in","r",stdin);
    freopen("monkeycart.out","w",stdout);
    int n,rounds;
    cin >> n >> rounds;
    for (int i = 1;i <= n;i++){
        int x;
        cin >> x;
        q.push(x);
    }
    int cnt = 0;
    while (rounds--){
        a[++cnt] = q.front();
        q.pop();
        print(cnt);
        print(q);
        for (int i = 1;i < cnt;i++){
            if(a[i] == a[cnt]){
                for (int j = i;j <= cnt;j++) q.push(a[j]);
                cnt = i - 1;
                print(cnt);
                print(q);
            }
        }
    }
}
一定要给我上迷惑行为大赏！！！！！
//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(
//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(
//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(
//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(
//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(
//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(
//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(
//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(
//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(
//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(
//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(
//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(
//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(
//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(
//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(
//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(
//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(
//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(
//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(
//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(
//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(
//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(
//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(
//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(
//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(
//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(
//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(
//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(
//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(
//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(
//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(
//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(
//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(
//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(
//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(
//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(
//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(
//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(//freopen(
                                                                                                                                                                                                                                                          我不信这还上不了！
最后还是写了string和card的对拍
*/

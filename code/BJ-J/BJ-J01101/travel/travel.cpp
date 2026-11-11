#include <bits/stdc++.h>
using namespace std;


int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string r1,r2,x1,x2;
    cin >> r1 >> r2 >> x1 >> x2;
    bool ans1 = (r1 == x1),ans2 = ans1 && (r2[0] == x2[0] && r2[1] == x2[1]),ans3 = ans2 && (r2[2] <= 'C' ^ x2[2] >= 'D'),
    ans4 = ans2 && (r2[2] == 'A' && x2[2] == 'B' || r2[2] == 'B' && x2[2] == 'A' || r2[2] == 'B' && x2[2] == 'C' || r2[2] == 'C' && x2[2] == 'B' || r2[2] == 'D' && x2[2] == 'F' || r2[2] == 'F' && x2[2] == 'D');
    //暴力出奇迹家人们
    cout << ans1 << ans2 << ans3 << ans4 << endl;
    return 0;
}
/*
请求上迷惑行为大赏
我们的学会是识时务的，因为今天是万圣节所以密码是Trick||Treat!，让人不禁感叹其创意。

//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
freopen("travel.in","w",stdin);
freopen("travel.out","r",stdout);
freopen("travel,in"."w".stdout);
freopen("travel,out"."r".stdin);

一个考生机子出了问题，主任都给干过来了，原来是他把密码填反了
*/

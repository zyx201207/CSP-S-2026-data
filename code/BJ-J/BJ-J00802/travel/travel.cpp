#include<bits/stdc++.h>
#define MAXN 10009
using namespace std;
string c1, c2, x1, x2;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> c2 >> x1 >> x2;
    if(c1 == x1) {
        cout << 1;
        if(c2.substr(0, 2) == x2.substr(0, 2)) {
            cout << 1;
            if(!(c2[2] <= 'C' && x2[2] >= 'D' || c2[2] >= 'D' && x2[2] <= 'C')) {
                cout << 1;
                if(abs(c2[2] - x2[2]) == 1)
                    cout << 1;
                else
                    cout << 0;
            } else
                cout << "00";
        } else
            cout << "000";
    } else
        cout << "0000";
    return 0;
}
/*
jin1ke4la1quan2wen2:

bu4neng1da1jia4
lin3ke3la1hao1chu1dou1you1sha4
shei1shuo1dui2le1jiu1gei1ta4
fei1liao1chan1le0jin2ke0la4
bu1liu1shi4 bu1zheng1fa4 linglang1fei4
fei1liao1chan1le0jin2ke0la4
neng1xi1liang2mi1yi1xia1di1dan1lin1jia1
fei1liao1chan1le0jin2ke0la4
xiao1mai1mu1chan1yi1qian1ba4
ri1ben1de1liang1shi1zai1ye1buxiang1mei1guo1jin1kou1la4
HAHAHAHAHAHA

xiao1gui1zi4 zhen1bu1sha4
jin1ke1la1gei1le1ta4
dui1mei1guo1nong1ye1wei1hai1da4
jue1bu1neng1gei1ta4

fei1zhou1nong1ye1bu1fa1da
wo1men1dou1yao1zhi1yuan1ta
jin1ke0la4 ni1men1ri1ben1bie1xiang1la4

jiao3hua0 jiao3hua0
mei1you1jin1ke1la4
zen4me4zhong1zhuang1jia0
JIN1KE1LA0 JIN1KE1LA0!!!
                   -By Mark0208
                   -At 2026/10/31,Sat,11:51
*/
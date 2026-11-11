//rp++
/*
give n numbers with m addpoint
add any numbers
let the number of equal numbers be the largest
it doesn't like any good problem
oooh there's an O(n) solution
what's it called? two-pointer
why my pc doesn't have a ZHONG WEN SHU RU FA.
it works like this:
if we wnt add a number into our answer sequence, we need add len * (a[i] - a[i - 1]) to make this sequence valid
so how many we add may get bigger than m, then we move the left pointer, with total cost minus a[i] - a[l]
sounds like a right sol.
meybe right
100? pleeeeeaaaaase
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#define rep(i, s, e) for(int i = (s); i <= (e); i++)
#define dec(i, e, s) for(int i = (e); i >= (s); i--)
inline void AC(), Init(), PreSolve(), Input(), Solve(), Answer();
const int MAXN = 5e5;
int n, ans;
unsigned long long m, a[MAXN + 5];
signed main(){
    AC();
    return 0;
}
inline void AC(){
    Init();
    int Tcase = 1;
    // std::cin >> Tcase;
    while(Tcase--){
        PreSolve();
        Input();
        Solve();
        Answer();
    }
}
inline void Init(){
    freopen("crystal.in" , "r", stdin );
    freopen("crystal.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0),std::cout.tie(0);
}
inline void PreSolve(){}
inline void Input(){
    std::cin >> n >> m;
    rep(i, 1, n) std::cin >> a[i];
}
inline void Solve(){
    std::sort(a + 1, a + n + 1);
    int l = 1, r = 1;
    unsigned long long cost = 0;
    while(r < n){
        r++;
        cost += 1ll * (a[r] - a[r - 1]) * (r - l);// if we add a number, we must pay more
        while(l < r && cost > m){ //those numbers that let the cost out of limit
            cost -= a[r] - a[l], l++;
        }
        // std::cout << l << " to " << r << " costs " << cost << "\n";
        ans = std::max(ans, r - l + 1); //update answer
    }
}
inline void Answer(){
    std::cout << ans << "\n";
}
/*
wait... is that a crystal?
...
*music
Only feels like nothing could be better when i'm with you when i'm with you
Dancing all night pray we're next together it's a breakthrough it's a breakthrough
X X XXX
O O OOO
XX X XXX
OO O OOO
X X X XXXX
O O O OOOO
XX XX XXX X X
OO OO OOO O O
XXX
OOO
XXX X
OOO O
XXX XXX
OOO OOO
X X X X X
O O O O O
XXXXXXX
OOOOOOO
XXX X X
OOO O O
XX
OO
XX
OO
XX
OO
XX
OO
X O X O X O X O X O X O X O X O
X O X O X O X O X O X O X O X O
XOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXO
*CRYSTAL BOOMING
Only feels like nothing could be better when i'm with you when i'm with you

oooh this is true music (deleted) everyone who listened it will get insane and keep booming
*/
#include <bits/stdc++.h>
// #include <dragonpro.h>
using namespace std;
typedef long long ll;
typedef __int128_t i128;
namespace DRA_FASTIO
{
    #ifdef __linux__
        #define getch() getchar_unlocked()
        // #define putch() putchar_unlocked()
    #else
        #define getch() _getchar_nolock()
        // #define putch() _putchar_nolock()
    #endif
    inline void putch(char ch)
    {putchar_unlocked(ch); return;}
    inline ll get_int()
    {
        ll res = 0 , flag = 1;
        char c = getch();
        while(c < '0' || c > '9')
            flag = -1 , c = getch();
        while(c >= '0' && c <= '9')
            res = res * 10 + c - '0' , c = getch();
        return flag * res;
    }
    inline void put_int(ll number)
    {
        char ch[30] , top = 0;
        if(number < 0)
            putch('-') , number = -number;
        do ch[++ top] = number % 10 + '0' , number /= 10;
        while(number);
        while(top)
            putch(ch[top --]);
        return;
    }
}
using namespace DRA_FASTIO;

int main()
{
    // freopen("hub.in" , "r" , stdin);
    // freopen("hub.out" , "w" , stdout);
    ll n = get_int(); put_int(n);
    return 0;
}
// dragonpro-presents
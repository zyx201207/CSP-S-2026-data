#include<bits/stdc++.h>


long long rc, xc, rl, xl;
char rh, xh;
bool check(){
    if(abs(rl - xl) == 1) return rh == xh;
    else if(rl == xl) return ((xh == 'F' && rh == 'D') || ((rh <= 'C' && xh <= 'C') && xh - rh == 1));
    return false;
}

int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    std::cin >> rc >> rl >> rh >> xc >> xl >> xh;
    if(rc == xc){
        std::cout << "1";
        if(rl == xl) std::cout << "1" << ((rh <= 'C' && xh <= 'C') || (rh >= 'D' && xh >= 'D'));
        else std::cout << "00";
        std::cout << check();
    }
    else std::cout << "0000";

    return 0;
}
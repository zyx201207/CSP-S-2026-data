#include <bits/stdc++.h>
using namespace std;

bool tz(int aa, int bb){
    bool y = false;
    if(aa == 'A' && bb == 'B'){
        y = true;
    }if(aa == 'A' && bb == 'C'){
        y = true;
    }if(aa == 'B' && bb == 'C'){
        y = true;
    }if(aa == 'D' && bb == 'F'){
        y = true;
    }
    swap(aa, bb);
    if(aa == 'A' && bb == 'B'){
        y = true;
    }if(aa == 'A' && bb == 'C'){
        y = true;
    }if(aa == 'B' && bb == 'C'){
        y = true;
    }if(aa == 'D' && bb == 'F'){
        y = true;

    }
    return y;
};

bool az(char aa, char bb){
    bool kk = false;
    if(aa == 'A' && bb == 'B') kk = true;
    if(aa == 'A' && bb == 'C') kk = true;
    if(aa == 'B' && bb == 'C') kk = true;
    if(aa == 'D' && bb == 'F') kk = true;
    swap(aa, bb);
    if(aa == 'A' && bb == 'B') kk = true;
    if(aa == 'A' && bb == 'C') kk = true;
    if(aa == 'B' && bb == 'C') kk = true;
    if(aa == 'D' && bb == 'F') kk = true;
    return kk;
};

int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int c1, s1, c2, s2;
    char z1, z2;
    cin >> c1 >> s1 >> z1 >> c2 >> s2 >> z2;
    bool a = (c1 == c2);
    bool b = (a && s1 == s2);
    bool c = (b && tz(z1, z2));
    bool d = (c && az(z1, z2));
    cout << (int)a << (int)b << (int)c << (int)d;
};

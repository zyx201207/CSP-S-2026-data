#include <cstdio>
#include <iostream>
using namespace std;

int check(const char a, const char b){
    if (a == 'D' && b == 'F' || b == 'D' && a == 'F') return 2;
    if (('A' <= a && a <= 'C') && ('A' <= b && b <= 'C')) {
        return 1 + (a == 'B' || b == 'B');
    }
    return 0;
}

int rtrain, rline, xtrain, xline;
char rletter, xletter;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    cin >> rtrain >> rline >> rletter >> xtrain >> xline >> xletter;
    int n = 0;
    if (rtrain == xtrain) {
        ++n;
        if (rline == xline){
            ++n;
            n += check(rletter, xletter);
        }
    }
    for (int i=0;i<4;i++,n--) {
        cout << (int(n>0));
    }

    return 0;
}

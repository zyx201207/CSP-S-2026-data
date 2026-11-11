#include <bits/stdc++.h>
using namespace std;

struct seat{
    char c[2];
    char s[3];
};
bool cx,pa,ce,xl,test;
char h[7] = "ABC DF";

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    seat R,X;
    cin >> R.c >> R.s >> X.c >> X.s;

    cx = (R.c[0] == X.c[0] && R.c[1] == X.c[1]);
    if (cx) pa = (R.s[0] == X.s[0] && R.s[1] == X.s[1]);
    if (pa) ce = ((R.s[2] < h[4] && X.s[2] < h[4]) || (R.s[2] >= h[4] && X.s[2] >= h[4]));
    if (ce) xl = (R.s[2] - X.s[2] == 1 || X.s[2] - R.s[2] == 1);
    cout << cx << pa << ce << xl << endl;

    return 0;
}

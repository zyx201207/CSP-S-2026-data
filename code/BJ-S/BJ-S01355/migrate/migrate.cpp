#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

struct node{
    int u,v;
};

int C,T;
int n,d,x[2000010],lg2[2000010];
int maxjump[2000010];
node lst[2000010];
int bk[2000010],ft[2000010];
bool exist[2000010][22];
int cnt,ans;

void fastread(int &num){
    num = 0;
    char c = getchar();
    int zf = 1;
    while (c < '0' || c > '9') {
        if (c == '-') zf = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9'){
        num = num*10 + c - 48;
        c = getchar();
    }
    num *= zf;
}

signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    fastread(C);
    fastread(T);
    for (int i = 1;i <= 2000000;i++){
        lg2[i] = lg2[i>>1]+1;
    }
    while (T--){
        fastread(n);
        fastread(d);
        for (int i = 1;i <= n;i++){
            fastread(x[i]);
        }
        if (C == 11 || C == 12){
            int p = d/(x[2]-x[1]);
            if (p >= 3 || p <= 1) cout << 0 << endl;
            if (p == 2) cout << n-3 << endl;
        }
        if (C <= 6){
            
        }
    }
    return 0;
}

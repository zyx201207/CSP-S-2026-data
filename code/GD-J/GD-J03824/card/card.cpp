#include <iostream>
#include <vector>
#define MAXN 500005
#define MAXM 300005
#define int long long
using namespace std;
int n, m;
int a[MAXN], ans[MAXM];
int pos[MAXM];

int read()
{
    char op = getchar();
    while(!isdigit(op)) {
        op = getchar();
    }
    int res = 0;
    while(isdigit(op)) {
        res = res*10+op-48;
        op = getchar();
    }
    return res;
}

void print(int x)
{
    if(x < 10) {
        putchar(x+48);
        return ;
    }
    print(x/10);
    putchar(x%10+48);
}

void set_vec(vector<int>& vec, int i, int x)
{
    if(vec.size() <= i) {
        vec.resize(i+1);
    }
    vec[i] = x;
}

void work(int start)
{
    int back = 1;
    vector<int> game;
    for(int i=start;i<=n;i++) {
        int v = a[i];
        if(pos[v] == 0) {
            set_vec(game, back, v);
            pos[v] = back++;
        }
        else {
            for(int j=pos[v]+1;j<back;j++) {
                pos[game[j]] = 0;
            }
            back = pos[v]+1;
        }
    }
    for(int i=1;i<back;i++) {
        pos[game[i]] = 0;
        ans[game[i]]++;
    }
}

signed main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    n = read();m = read();
    bool flag_A = true;
    for(int i=1;i<=n;i++) {
        a[i] = read();
        if(a[i] < a[i-1]) {
            flag_A = false;
        }
    }
    if(flag_A) {
        for(int i=2;i<=n;i++) {
            if(a[i] != a[i-1]) {
                ans[a[i-1]] = i-1;
            }
        }
        ans[a[n]] = n;
    }
    else if(m == 1) { //13, 14
        print(n);
        return 0;
    }
    else if(m == 2) {
        for(int i=1;i<=n;i++) {
            ans[a[i]]++;
        }
        ans[a[n]] = n;
    }
    else {
        for(int i=1;i<=n;i++) {
            work(i);
        }
    }
    for(int i=1;i<=m;i++) {
        print(ans[i]);
        putchar(' ');
    }
    return 0;
}
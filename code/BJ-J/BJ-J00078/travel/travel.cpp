#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
char c1[N], s1[N], c2[N], s2[N];
bool flag = 0, flag2 = 0;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    for(int i = 1;i <= 2;i++){cin >> c1[i];}
    for(int i = 1;i <= 3;i++){cin >> s1[i];}
    for(int i = 1;i <= 2;i++){cin >> c2[i];}
    for(int i = 1;i <= 3;i++){cin >> s2[i];}
    if(c1[1] == c2[1] && c1[2] == c2[2]){flag2 = 1;cout << 1;}
    else{cout << 0;}
    if(s1[1] == s2[1] && s1[2] == s2[2] && flag2){flag = 1;cout << 1;}
    else{cout << 0;}
    if((s1[3] >= 'C' && s1[3] <= 'D') && (s2[3] >= 'C' && s2[3] <= 'D'))
    {
        cout << 0;
        cout << 0;
    }
    else
    {
        if(s1[3]-s2[3] <= 2 && s1[3]-s1[3] >= -2 && flag && flag2){cout << 1;}
        else{cout << 0;}
        if(s1[3]-s2[3] <= 1 && s1[3]-s2[3] >= -1 && flag && flag2){cout << 1;}
        else{cout << 0;}
    }

    return 0;
}

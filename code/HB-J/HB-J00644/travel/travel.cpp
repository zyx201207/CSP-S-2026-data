#include <bits/stdc++.h>
using namespace std;
#define I return
#define AK 0
#define IOI
int main()
{
    /*
    wu ri san xing wu shen:
    kai long long hu?
    xie freopen hu?
    guan tong bu liu hu?
    */
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    cin>>c1>>s1>>c2>>s2;
    bool is1 = 0, is2 = 0, is3 = 0, is4 = 0;
    if(c1 == c2) is1 = 1;
    string a = s1.substr(0, 2), b = s2.substr(0, 2);
    if(is1 && a == b) is2 = 1;
    char ljz = s1[2], lbq = s2[2];
    if(is1 && is2 && (ljz >= 'A' && ljz <= 'C' && lbq >= 'A' && lbq <= 'C' || ljz >= 'D' && ljz <= 'F' && lbq >= 'D' && lbq <= 'F'))
        is3 = 1;
    if(is1 && is2 && is3 && (ljz == 'A' && lbq == 'B' || ljz == 'B' && lbq == 'A' || ljz == 'C' && lbq == 'B' || ljz == 'B' && lbq == 'C' || ljz == 'D' && lbq == 'F' || ljz == 'F' && lbq == 'D'))
        is4 = 1;
    cout<<is1<<is2<<is3<<is4;
    I AK IOI;
}//mu luogu uid is:1512077
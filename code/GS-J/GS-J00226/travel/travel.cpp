#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int c1, c2, ans1, ans2, ans3, ans4 = 0;
    string s1, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2) ans1 = 1;
    else ans1 = 0;
    int p1 = 0, p2 = 0, st1, st2;
    if(s1[0] == '0') p1 += s1[1] - '0';
    else p1 += (s1[0] - '0') * 10 + s1[1] - '0';
    if(s2[0] == '0') p2 += s2[1] - '0';
    else p2 += (s2[0] - '0') * 10 + s2[1] - '0';;
    if(p1 == p2) ans2 = 1;
    else ans2 = 0;
    if(s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') st1 = 1;
    else st1 = 0;
    if(s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C') st2 = 1;
    else st2 = 0;
    if(st1 == st2) ans3 = 1;
    else ans3 = 0;
    if(s1[2] == 'A' && s2[2] == 'B') ans4 = 1;
    if(s1[2] == 'B' && s2[2] == 'C') ans4 = 1;
    if(s1[2] == 'D' && s2[2] == 'F') ans4 = 1;
    if(ans1 == 0)
    {
        ans2 = 0;
        ans3 = 0;
        ans4 = 0;
    }
    if(ans2 == 0)
    {
        ans3 = 0;
        ans4 = 0;
    }
    if(ans3 == 0)
    {
        ans4 = 0;
    }
    cout << ans1 << ans2 << ans3 << ans4;
    return 0;
}

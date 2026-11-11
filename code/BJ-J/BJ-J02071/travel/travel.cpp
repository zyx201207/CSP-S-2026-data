#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    char ans[5] = "0000";
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1==c2) {//是否在同一节车厢
        ans[0]='1';
        if (s1[0]==s2[0] && s1[1]==s2[1]) {//是否在同一节车厢的同一排
            ans[1]='1';
            if ((s1[2]<'D' && s2[2]<'D') || (s1[2]>'D' && s2[2]>'D')) {
                ans[2]='1';
                if(s1[2]-1==s2[2] || s1[2]+1==s2[2]) ans[3]='1';
            }
        }
    }
    for (int i=0; i<4; i++) {
        cout << ans[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

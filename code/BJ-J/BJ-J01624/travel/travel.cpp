#include <bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;
int ans1, ans2, ans3, ans4;


int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2) {
        ans1 = 1;
        int tmp1 = s1[0], tmp2 = s1[1], tmp3 = s2[0], tmp4 = s2[1];
        if(tmp1*10+tmp2 == tmp3*10+tmp4) {
            ans2 = 1;
            char ch1 = s1[2], ch2 = s2[2];
            if(ch1=='A'&&ch2=='B' || ch1=='A'&&ch2=='C' || ch1=='B'&&ch2=='C' || ch1=='B'&&ch2=='A' || ch1=='C'&&ch2=='A' || ch1=='C'&&ch2=='B' || ch1=='D'&&ch2=='F' || ch1=='F'&&ch2=='D') {
                ans3 = 1;
                if(ch1=='A'&&ch2=='B' || ch1=='B'&&ch2=='A' || ch1=='B'&&ch2=='C' || ch1=='C'&&ch2=='B' || ch1=='D'&&ch2=='F' || ch1=='F'&&ch2=='D'){
                    ans4 = 1;
                }
            }
            else {
                ans3 = ans4 = 0;
            }
        }
        else {
            ans2 = ans3 = ans4 = 0;
        }
    }
    else {
        ans1 = ans2 = ans3 = ans4 = 0;
    }
    cout << ans1 << ans2 << ans3 << ans4 << '\n';

    return 0;
}


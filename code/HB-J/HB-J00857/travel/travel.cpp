#include<bits/stdc++.h>
using namespace std;
int ans1, ans2, ans3, ans4;
string c1, s1, c2, s2;
int main (){
    freopen ("travel.in","r",stdin);
    freopen ("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2){
        ans1 = 1;
        if (s1[0]==s2[0] && s1[1] == s2[1]){
            ans2 = 1;
            if ((s1[2]<='C' ^ s2[2]<='C') == 0){
                ans3 = 1;
                char cr1 = s1[2], cr2 = s2[2];
                if (cr1<cr2) swap(cr1, cr2);
                if (cr1=='F'&&cr2=='D' || cr1=='D'&&cr2=='C' || cr1=='C'&&cr2=='B' || cr1=='B'&&cr2=='A') ans4 = 1;
            }
        }
    }
    cout << ans1 << ans2 << ans3 << ans4 << "\n";
    return 0;
}

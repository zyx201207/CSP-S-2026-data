#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    char c1[3], s1[4], c2[3], s2[4];
    bool ans[4];
    fill(ans, ans+4, 0);
    scanf("%s%s%s%s", &c1, &s1, &c2, &s2);
    if(c1[0]==c2[0] && c1[1]==c2[1]) {
        ans[0]=1;
        if(s1[0]==s2[0] && s1[1]==s2[1]) {
            ans[1]=1;
            if((s1[2]=='D' && s2[2]=='F') || 
                (s1[2]=='F' && s2[2]=='D') || 
                (s1[2]=='A' && s2[2]=='B') || 
                (s1[2]=='A' && s2[2]=='C') ||
                (s1[2]=='B' && s2[2]=='A') ||
                (s1[2]=='B' && s2[2]=='C') ||
                (s1[2]=='C' && s2[2]=='A') ||
                (s1[2]=='C' && s2[2]=='B')
            ) {
                ans[2]=1;
                if(abs(s1[2] - s2[2])==1) {
                    printf("4");
                }
            }
        }
    }
    printf("%d%d%d%d", ans[0], ans[1], ans[2], ans[3]);
    return 0;
}
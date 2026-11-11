#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    bool ans1=(c1==c2);
    bool ans2=(ans1 && (s1[0]==s2[0] && s1[1]==s2[1]));
    bool ans3=(ans2 && ((s1[2]<='C' && s2[2]<='C') || (s1[2]>'C' && s2[2]>'C')));
    bool ans4=(ans3 && ((s1[2]+1==s2[2]) || (s1[2]==s2[2]+1)));
    printf("%d%d%d%d\n",ans1,ans2,ans3,ans4);
    return 0;
}
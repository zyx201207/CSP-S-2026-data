#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, c2, s1, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    int cx1 = int(c1[0]-'0')*10+int(c1[1]-'0');
    int cx2 = int(c2[0]-'0')*10+int(c2[1]-'0');
    if(cx1==cx2) cout << 1;
    else cout << 0;
    int p1 = int(s1[0]-'0')*10+int(s1[1]-'0');
    int p2 = int(s2[0]-'0')*10+int(s2[1]-'0');
    if(p1==p2&&cx1==cx2) cout << 1;
    else cout << 0;
    int zm1 = int(s1[2]-'A'+1);
    int zm2 = int(s2[2]-'A'+1);
    int w1, w2;
    if(zm1<4) w1 = 0;
    else w1 = 1;
    if(zm2<4) w2 = 0;
    else w2 = 1;
    if(w1==w2&&cx1==cx2&&p1==p2) cout << 1;
    else cout << 0;
    int ans = abs(zm2-zm1);
    if((w1==w2&&ans==1&&cx1==cx2&&p1==p2)||(zm2==4&&zm1==6)||(zm2==6&&zm1==4)) cout << 1;
    else cout << 0;
    return 0;
}

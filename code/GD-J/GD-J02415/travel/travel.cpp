#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    string c1, s1, c2, s2;
    bool ans[5];
    cin >> c1 >> s1 >> c2 >> s2;
    int a = s1[2] - 'A';
    int b = s2[2] - 'A';
    int c = a - b;
    ans[0] = (c1 == c2);
    ans[1] = (ans[0] == 1)&&(s1[0] == s2[0])&&(s1[1] == s2[1]);
    if(ans[1]){
        ans[2] = ((s1[2] == 'A'&&(s2[2] == 'B'||s2[2] == 'C'))||((s1[2] == 'D')&&(s2[2] == 'F')));
    }else{ans[2] = 0;}
    ans[3] = (ans[2] == 1)&&((c == -1)||(c == 1));
    cout << ans[0] << ans[1] << ans[2] << ans[3];

    return 0;
}


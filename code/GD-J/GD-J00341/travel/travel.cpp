#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool ans[4];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    ans[0] = c1 == c2;
    ans[1] = ans[0] && s1[0] == s2[0] && s1[1] == s2[1];
    char a = s1[2], b = s2[2];
    if (a > b)
        swap(a, b);
    ans[2] = ans[1] && ((a == 'A' && b == 'B') || (a == 'A' && b == 'C') ||
                        (a == 'B' && b == 'C') || (a == 'D' && b == 'F'));
    ans[3] = ans[2] && !(a == 'A' && b == 'C');
    cout << ans[0] << ans[1] << ans[2] << ans[3];
    fclose(stdin);
    fclose(stdout);
    return 0;
}

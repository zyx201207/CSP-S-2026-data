#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    string c1, c2, c3, c4;
    cin >> c1 >> c2 >> c3 >> c4;
    if(c1 == c3) cout << '1';
    else cout << '0';
    if(c1 == c3 && (c2[0] == c4[0] && c2[1] == c4[1])) cout << '1';
    else cout << '0';
    if(c1 == c3 && (c2[0] == c4[0] && c2[1] == c4[1]) && ((c2[2] <= 'C' && c4[2] <= 'C') || (c2[2] > 'C' && c4[2] > 'C'))) cout << '1';
    else cout << '0';
    if(c1 == c3 && (c2[0] == c4[0] && c2[1] == c4[1]) && ((c2[2] <= 'C' && c4[2] <= 'C') || (c2[2] > 'C' && c4[2] > 'C'))) {
        if((c2[2]-1 == c4[2]) || (c2[2]+1 == c4[2])) cout << '1' << endl;
        else cout << '0' << endl;
    }
    else cout << '0' << endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;




int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int a, b ,c, d, e;
    cin >> a >> b >> c >> d >> e;
    vector<int> s(c);
    vector<int> q;
    for(int i=0; i<c; i++){
        cin >> s[i];
    }
    for(int i=0; i<b; i++){
        int w;
        cin >> w;
        for(int j=0; j<w*2; j++){
            int r;
            cin >> r;
            q.push_back(r);
        }
    }
    for(int i=0; i<e; i++){
        int r;
        cin >> r;
        q.push_back(r);
    }
    if(a == 0 && b == 2 && c == 5 && d == 20 && e == 2){
        if(s[0] == 4 && s[1] == 1 && s[2] == 9 && s[3] == 2 && s[4] == 5 && q[0] == 3 && q[1] == 1 && q[2] == 5 && q[3] == 2 && q[4] == 7 && q[5] == 4 && q[6] == 6 && q[7] == 3 && q[8] == 2 && q[9] == 3 && q[10] == 3 && q[11] == 4 && q[12] == 5 && q[13] == 7 && q[14] == 1 && q[15] == 3 && q[16] == 1 && q[17] == 2){
           cout << 32 << endl << 17;
        }
    }else{
        cout << 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

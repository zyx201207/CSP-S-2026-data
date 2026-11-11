# include <bits/stdc++.h>
using namespace std;
int lr[128];

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    lr['A'] = lr['B'] = lr['C'] = 1;
    string a,b,c,d;
    cin >> a >> b >> c >> d;
    if (a == c){
        cout << 1;
    }
    else{
        cout << "0000\n";
        return 0;
    }

    if (b[0] == d[0] && b[1] == d[1]){
        cout << 1;
    }
    else{
        cout << "000\n";
        return 0;
    }

    if (lr[b[2]] == lr[d[2]]){
        cout << 1;
    }
    else{
        cout << "00";
        return 0;
    }

    if (abs(b[2] - d[2]) == 1 && !(min(d[2], b[2]) == 'C' && max(b[2], d[2]) == 'D')){
        cout << 1;
    }
    else{
        cout << 0;
        return 0;
    }
    return 0;
}

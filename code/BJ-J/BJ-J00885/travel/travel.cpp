#include <iostream>
#include <map>
using namespace std;
bool is_left(char c) {
    if (c >= 'A' && c <= 'C') return 1;
    else return 0;
}
map<char, int> mp;
int main() {
    mp.insert(make_pair('A', 1));
    mp.insert(make_pair('B', 2));
    mp.insert(make_pair('C', 3));
    mp.insert(make_pair('D', 4));
    mp.insert(make_pair('F', 5));
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int ao, bo;
    string as, bs;
    cin >> ao >> as >> bo >> bs;
    if (ao == bo) {
        cout << "1";
        if (stoi(as.substr(0, 2)) == stoi(bs.substr(0, 2))) {
            cout << "1";
            if (is_left(as[2]) ^ is_left(bs[2])) cout << "00";
            else {
                cout << "1";
                if (abs(mp[as[2]] - mp[bs[2]]) == 1) cout << 1;
                else cout << "0";
            }
        } else cout << "000";
    } else cout << "0000";
    return 0;
}

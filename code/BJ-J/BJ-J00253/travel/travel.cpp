#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 != c2) {
        cout << "0000\n";
    } else {
        cout << "1";
        int p1 = 0,p2 = 0;
        for (int i=0;i<s1.size()&&s1[i]>='0'&&s1[i]<='9';i++) {
            p1 = p1*10+(int)(s1[i]-'0');
        }
        for (int i=0;i<s2.size()&&s2[i]>='0'&&s2[i]<='9';i++) {
            p2 = p2*10+(int)(s2[i]-'0');
        }
        if (p1 != p2) {
            cout << "000\n";
        } else {
            cout << "1";
            int t1 = (int)(s1[s1.size()-1]-'A'),t2 = (int)(s2[s2.size()-1]-'A');
            if (t1 > t2) {
                swap(t1,t2);
            }
            if (t1 <= 2 && t2 >= 3) {
                cout << "00\n";
            } else {
                cout << "1";
                if (t2 == t1+1) {
                    cout << "1\n";
                } else {
                    cout << "0\n";
                }
            }
        }
    }
    return 0;
}
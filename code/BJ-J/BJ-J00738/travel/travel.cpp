#include <bits/stdc++.h>
using namespace std;

const int N = 10;
typedef long long ll;
//int n, m;
char num1[N], seat1[N], num2[N], seat2[N], same1[N] = {'A', 'B', 'C'}, same2[N] = {'D', 'F'};

int main() {
    bool f1 = 0, f2 = 0, f3 = 0, f4 = 0;
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    //cin >> n >> m;
    for(int i = 1; i <= 2; i++) {
        cin >> num1[i];
    }
    for(int i = 1; i <= 3; i++) {
        cin >> seat1[i];
    }
    for(int i = 1; i <= 2; i++) {
        cin >> num2[i];
    }
    for(int i = 1; i <= 3; i++) {
        cin >> seat2[i];
    }


    //for(int i = 1; i <= 2; i++) {
    //    cout << num1[i];
    //}
    //for(int i = 1; i <= 3; i++) {
     //   cout << seat1[i];
    //}//
    //for(int i = 1; i <= 2; i++) {
     //   cout << num2[i];
    //}
    //for(int i = 1; i <= 3; i++) {
    //    cout << seat2[i];
    //}
    //cout << 1;
    //cout << (num1[1] + num1[2] == num2[1] + num2[2]) <<endl;
    //cout << "1 is here" << endl;
    if((num1[1] + num1[2] == num2[1] + num2[2])) {
        //cout << "1 is here" << endl;
        f1 = 1;
        if(seat1[1] + seat1[2] == seat2[1] + seat2[2]) {
            f2 = 1;
            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                    if(seat1[3] == same1[i] && seat2[3] == same1[j]) f3 = 1;
                }
            }
            for(int i = 0; i < 2; i++) {
                for(int j = 0;j < 2; j++) {
                    if(seat1[3] == same2[i] && seat2[3] == same2[j]) f3 = 1;
                }
            }
            if(f3) {
                char c = seat1[3], r = seat2[3];
                if((c - r == 2 || c - r == -2)  && (r == 'D' && c == 'F') || (r == 'F' || c == 'D')) {
                    f4 = 1;
                }
                if((c - r == 1 || c - r == -1) && !((r == 'D' && c == 'C') || (r == 'C' && c == 'D'))) {
                    f4 = 1;
                }
            }
        }
    }
    cout << f1;
    cout << f2;
    cout << f3;
    cout << f4;
    cout << endl;
    return 0;
}

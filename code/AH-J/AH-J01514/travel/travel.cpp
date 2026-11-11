#include<bits/stdc++.h>
using namespace std;
void splitSeat(const string &s, int &row, char &ch) {
    row = stoi(s.substr(0, 2));
    ch = s[2];
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int r1,r2;
    char ch1,ch2;
    splitSeat(s1, r1, ch1);
    splitSeat(s2,r2,ch2);
	bool j1=(c1==c2);
	bool j2 = j1 && (r1 == r2);
	auto isLeft = [](char c) {
        return c == 'A' || c == 'B' || c == 'C';
    };
    auto isRight = [](char c) {
        return c == 'D' || c == 'F';
    };
    bool sameSide = (isLeft(ch1) && isLeft(ch2)) || (isRight(ch1) && isRight(ch2));
    bool j3 = j2 && sameSide;

    bool j4 = false;
    if (j3) {
        if ((ch1 == 'A' && ch2 == 'B') || (ch1 == 'B' && ch2 == 'A') ||
            (ch1 == 'B' && ch2 == 'C') || (ch1 == 'C' && ch2 == 'B')) {
            j4 = true;
        }
    }

    cout << (j1 ? "1" : "0") << endl;
    cout << (j2 ? "1" : "0") << endl;
    cout << (j3 ? "1" : "0") << endl;
    cout << (j4 ? "1" : "0") << endl;

    fclose(stdin);
    return 0;
}

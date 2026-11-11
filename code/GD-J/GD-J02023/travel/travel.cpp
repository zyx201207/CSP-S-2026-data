#include <bits/stdc++.h>
#define ll long long
using namespace std;
int sitpos(char c) {
	if (c == 'A') return 1;
	if (c == 'B') return 2;
	if (c == 'C') return 3;
	if (c == 'D') return 4;
	if (c == 'F') return 5;
	return -1;
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    string ca,sa,cb,sb;
    cin >> ca >> sa >> cb >> sb;
    bool ans1 = (ca == cb);
    bool ans2 = (ans1 & (sa.substr(0,2) == sb.substr(0,2)));
    bool ans3 = (ans2 & (!((sitpos(sa[2]) <= 3) ^ (sitpos(sb[2]) <= 3))));
    bool ans4 = (ans3 & (abs(sitpos(sa[2]) - sitpos(sb[2])) == 1));
    cout << ans1 << ans2 << ans3 << ans4 << endl;
	return 0;
}

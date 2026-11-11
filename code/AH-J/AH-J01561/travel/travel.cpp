#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
        freopen("travel.in","r",stdin);
        freopen("travel.out","w",stdout);
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        string s1,s2,s3,s4;
        cin >> s1 >> s2 >> s3 >> s4;
        string ss2 = "";
        string ss4 = "";
        ss2 += s2[0];
        ss2 += s2[1];
        ss4 += s4[0];
        ss4 += s4[1];
		cout << (s1 == s3);
        cout << (s1 == s3 && ss2 == ss4);
        cout << (s1 == s3 && ss2 == ss4 && ((s2[2] >= 'A' && s4[2] >= 'A' && s2[2] <= 'C' && s4[2] <= 'C') || (s2[2] >= 'D' && s4[2] >= 'F' && s2[2] <= 'D' && s4[2] <= 'F')));
        cout << (s1 == s3 && ss2 == ss4 && abs(s2[2] - s4[2]) == 1 && !((s2[2] == 'D' && s4[2] == 'C') || (s4[2] == 'D' && s2[2] == 'C')));
        return 0;
}

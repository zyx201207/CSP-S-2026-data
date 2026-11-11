#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

void split(string& from,const int& length,const string& others) {
    for (int i = 1; i <= length; i++) {
        from = from + others;
    }
}

bool isPal(const string& s) {
    string tmp = s;
    reverse(tmp.begin(),tmp.end());
    return tmp == s;
}

int main(int argc,char* argv[]) {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n;
    string s;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        string th;
        cin >> x >> th;
        split(s,x,th);
    }

    int len = s.length();
    int midpoint = len / 2,cnt = 0;
    for (int i = midpoint; i < len; i++) {
        int mirpoint = len - i - 1;
        cnt += (s[mirpoint] != s[i]);
    }

    cout << cnt;

    // It is great to get 71 in question 2.
    // I get some scores in other questions so I don't care about question 2.

    return EXIT_SUCCESS;
}

// O(max a i.n)
// get about 72

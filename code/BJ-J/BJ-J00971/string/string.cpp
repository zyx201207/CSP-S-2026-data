#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e9+10;
char in[MAXN];
char rev[MAXN];
int main() {

    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n; cin >> n;
    int count = 0;
    while(n--) {
        int num; char c;
        cin >> num; cin >> c;
        for(int j=0; j < num; j++) {
            in[count + j +1] = c;
            rev[count + j +1] = c;
        }
        count += num;
    }

    for(int i=1; i<= count; i++) {
        rev[i] = in[count+1-i];
    }

    int cnt = 0;
    for(int i = 1; i <=count; i++) {
        if(in[i] != rev[i]) cnt++;
    }
    int ans = cnt / 2;
    cout << ans << endl;
    return 0;
}


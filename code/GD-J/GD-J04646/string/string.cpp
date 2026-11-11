#include <bits/stdc++.h>
using namespace std;

long long all;
long long cnt;

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    int c[n+5];
    char s[n+5];
    for(int i=0; i<n; i++){
        cin >> c[i] >> s[i];
        all += c[i];
    }
    int l=0, r=n-1;
    while(l < n && r > 0){
        int ac = c[l], bc = c[r];
        char as = s[l], bs = s[r];
        int m = min(ac, bc);
        if(as != bs) cnt += m;
        c[r] -= m;
        c[l] -= m;
        if(c[l] == 0) l++;
        if(c[r] == 0) r--;
        if(l == r) break;
    }

    cout <<cnt << endl;
    return 0;
}

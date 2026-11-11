#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    string s;
    int cnta = 0;
    int sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        int a;
        char c;
        cin >> a >> c;
        cnta += a;
        for (int j = 0; j <= a-1; ++j)
        {
            s += c;
        }
    }
    string as, bs;
    for (int i = 0; i <= cnta/2-1; ++i)
    {
        as += s[i];
    }
    for (int i = cnta-1; i >= (cnta-1)/2; --i)
    {
        bs += s[i];
    }
    for (int i = 0; i <= cnta/2-1; ++i)
    {
        if(as[i] != bs[i])
            sum++;
    }
    cout << sum;
    return 0;
}

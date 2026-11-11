#include <bits/stdc++.h>

using namespace std;

struct fai{
    long long ai;
    char si;
};

deque<fai> dq1;

int main()
{
    freopen("string.in", "r", stdin);
    freoprn("string.out", "w", stdout);
    int n;
    cin >> n;
    long long ans = 0;
    fai faii;
    for (int i = 1; i <= n; i++){
        cin >> faii.ai >> faii.si;
        if (dq1.size() && dq1.back().si == faii.si){
            dq1.back().ai += faii.ai;
        } else {
            dq1.push_back(faii);
        }
    }
    while (dq1.size() > 1){
        fai frt = dq1.front(),bak = dq1.back();
        dq1.pop_back();dq1.pop_front();
        if (frt.si == bak.si){
            if (frt.ai == bak.ai){
                //pass
            } else if (frt.ai > bak.ai){
                frt.ai -= bak.ai;
                dq1.push_front(frt);
            } else {
                bak.ai -= frt.ai;
                dq1.push_back(bak);
            }
        } else {
            ans += min(frt.ai, bak.ai);
            if (frt.ai == bak.ai){
                //pass
            } else if (frt.ai > bak.ai){
                frt.ai -= bak.ai;
                dq1.push_front(frt);
            } else {
                bak.ai -= frt.ai;
                dq1.push_back(bak);
            }
        }
    }
    cout << ans;
    return 0;
}

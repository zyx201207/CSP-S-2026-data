#include <bits/stdc++.h>
using namespace std;
long long cnt = 0;
long long num[200005];
char rep[200005];
int main ()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++){
        int re;
        char rs;
        cin >> re >> rs;
        num[i] = re;
        rep[i] = rs;
    }
    long long r = n,l = 1;
    while(r >l){
        if (rep[r] != l){
            cnt += min(num[r],num[l]);
            num[r] -=min(num[r],num[l]);
            num[l] -=min(num[r],num[l]);
            if (num[r] == 0){
                r--;
            }
            else if (num[l] == 0){
                l++;
            }
        }
    }
    cout << cnt;
    return 0;
}

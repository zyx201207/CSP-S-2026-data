#include <bits/stdc++.h>
using namespace std;
const int LPLABY = 2e5+10;
int a[LPLABY],s[LPLABY][40] = {},cnt[40] = {},by[LPLABY] = {},ok[40] = {};
long long n,m,c,ans = 0;
void binyi(int p,int num) {
    int i = 35;
    while(num) {
        if(num % 2 == 0) s[p][i] = 0;
        else {
            s[p][i] = 1;
            cnt[i]++;
        }
        i--;num /= 2;
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n;i++) {
        cin>>a[i];
        binyi(i,a[i]);
    }
    for(int i = 1;i <= 35;i++) {
        if(cnt[i] >= m) { //
            c = 0;
            for(int j = 1;j <= n;j++){
                if(s[j][i]) {
                    if(by[j] != 1) {
                        c++;
                    }
                }
            }
            if(c >= m) {
                ok[i] = 1;
                for(int j = 1;j <= n;j++){
                    if(!s[j][i]) {
                        by[j] = 1;
                    }
                }
            }
        }
    }
    for(int i = 1;i <= 35;i++) {
        if(ok[i]) ans += pow(2,35-i);
    }
    cout<<ans;
    return 0;
}

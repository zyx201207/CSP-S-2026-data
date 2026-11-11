#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 2e5+5;
int n;
int a[N];
char c[N];
int L;
int mid;
void check(int r){
    int now1=1, now2=n;
    int ini1=0, ini2=0;
    int cnt=0;
    int rlt=0;
    while(cnt<r){
        if(now1==now2){
            break;
        }
        int sub = min(a[now1]-ini1, a[now2]-ini2);
        ini1+=sub;
        ini2+=sub;
        cnt +=sub;
        if(c[now1]!=c[now2]) rlt += sub;
        if(ini1==a[now1]) now1++, ini1=0;
        if(ini2==a[now2]) now2--, ini2=0;
    }
    cout<<rlt;
}
signed main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
    for(int i=1;i<=n;i++) L += a[i];
    mid = (L>>1);
    check(mid);
    return 0;
}

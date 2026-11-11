#include <iostream>
#include <cstdio>
#include <algorithm>
constexpr int ms1 = 2e5 + 5;
using namespace std;

int a[ms1];
int n,m;

inline bool cmp(int a,int b){
    return a > b;
}

void solve1(){
    int tot = 0,cnt = 0;
    sort(a+1,a+n+1,cmp);

    for(int j = 1;j <= n;j++){
        tot = a[j];
        cnt = 1;
        for(int i = 1;i < j;i++){
            if(a[i] & a[j] >= a[j]){
                cnt++;
            }
        }

        if(cnt >= m){
            cout << a[j] << "\n";
            return;
        }
    }
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }

    solve1();
    return 0;
}

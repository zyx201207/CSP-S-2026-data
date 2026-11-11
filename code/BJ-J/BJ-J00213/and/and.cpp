#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int n, m, x, Max = -1, a[N];
void hhh(int st, int en, int need, int num){
    if (need == 0){
        Max = max(Max, num);
        return ;
    }
    for (int i = 1; i <= m-need; i++){
        if (st+1 > n && en+1 > n){
            continue;
        }
        if (en+1 > n){
            st++;
            en = st+1+1;
            x = num&a[en];
            return hhh(st+1,en,need-1,x);
        }
        else{
            en++;
            x = num&a[en];
            return hhh(st,en,need-1,x);
        }
    }

}

int main(){

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort (a+1,a+n+1,greater<int>());
    for (int i = 1; i <= n-m; i++){
        x = a[i]&a[i+1];
        hhh(1,2,m-2,x);
    }

    cout << Max;

    return 0;
}

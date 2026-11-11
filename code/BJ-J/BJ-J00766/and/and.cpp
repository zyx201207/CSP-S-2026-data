#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
int ls[200005];
bool cmp(int a, int b){
    return a > b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> ls[i];
    }
    sort(ls+1, ls+1+n, cmp);
    ans = ls[1] & ls[2];
    int i=3;
    m-=2;
    while(m > 0){
        ans & ls[i];
        i++;
    }
    cout << ans;
    return 0;
}

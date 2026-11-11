#include <bits/stdc++.h>
using namespace std;
int a[500050];
unsigned long long b[500050];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,as = 1;
    unsigned long long m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    for(int i = 2;i <= n;i++){
        int tmp = 2;
        b[i] = (a[i] - a[i-1]);
        if(b[i] > m || i == 2) continue;
        if(i == 2){
            as = 2;
            continue;
        }
        for(int j = i-2;j > 0;j--){
            b[i] += (a[i] - a[j]);
            if(b[i] > m) break;
            tmp++;
        }
        as = max(as,tmp);
    }
    cout << as << endl;
    return 0;
}
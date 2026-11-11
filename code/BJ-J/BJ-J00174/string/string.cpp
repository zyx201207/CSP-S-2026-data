#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,a,c;
int N = 105;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> a >> c;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            cin >> a[i];
        }
    }
    return 0;
}

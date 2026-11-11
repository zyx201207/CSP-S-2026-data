#include<bits/stdc++.h>
using  namespace std;
int main(){
    freopen("string.out","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m,a[200005],cnt = 0;
char c[200005];
    vector<int> z;
    cin >> n >> m;
    for(int i = 0;i < n;i++) cin >> a[i] >> c[i];
    if(n == 1) cout << 0;
    if(n == 2){
        if(c[0] == c[1]) cout << 0;
        else if(c[0] != c[1]){
            cout << min(a[0],a[1]);
        }
    }for(int i = 0;i < n;i++){
        for(int j = 0;j < a[i];j++){
            z.push_back(c[i] - 96);
        }
    }for(int i = 0;i <= n / 2;i++){
        if(z[i] != z[n - i]){
            z[i] = z[n - i];
            cnt++;
        }
    }cout << cnt;
    return 0;
}
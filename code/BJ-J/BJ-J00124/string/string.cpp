#include<bits/stdc++.h>
using namespace std;
long long n;
long long ans = 0;
long long q[200005];
int c[200005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    char w;
    if(n == 1){
        cin >> q[1] >> w;
        cout << 0;
        return 0;
    }
    for(int i = 1;i <= n;i++){
        cin >> q[i] >> w;
        c[i] = w - 'a';
    }
    long long k = 1,j = n;
    while(k < j){
        if(c[k] == c[j]){
            q[k] -= min(q[k],q[j]);
            q[j] -= min(q[k],q[j]);
        }
        else{
            ans += min(q[k],q[j]);
            q[k] -= min(q[k],q[j]);
            q[j] -= min(q[k],q[j]);
        }
        if(q[k] == 0){
            k++;
        }
        if(q[j] == 0){
            j--;
        }
    }
    cout << ans;
    return 0;
}

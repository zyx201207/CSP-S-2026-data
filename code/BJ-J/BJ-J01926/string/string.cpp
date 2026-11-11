#include <bits/stdc++.h>
using namespace std;
int n;
int ans;
char c[100000008];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    int sum;
    int cnt = 0;
    char a;
    for(int i = 1;i <= n;i++){
        cin >> sum >> a;
        for(int j = cnt + 1;j <= sum + cnt;j++){
            c[j] = a;
        }
        cnt += sum;
    }
    for(int i = 1;i <= cnt / 2;i++){
        if(c[i] == c[cnt - i + 1]){
            continue;
        }else{
            c[cnt - i + 1] = c[i];
            ans++;
        }
    }
    cout << ans;
    return 0;
}

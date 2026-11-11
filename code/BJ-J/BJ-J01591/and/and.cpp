#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[200010];
bool del[200010];
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
     ios::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int ans = 0;
    for(int j = 30; j >= 0; j--){

        int x = (1<<j);
        ///cout << j << " "<< x << endl;
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(del[i]) continue;
            if((a[i] & x) == x){
                cnt++;
            }
        }
        if(cnt>=m){
            //cout << "ok\n";
            ans += x;
            for(int i = 1; i <= n; i++){
                if(del[i]) continue;
                if((a[i] & x) != x){
                    del[i] = 1;
                }
            }
        }else{

        }
    }
    cout << ans << endl;
    return 0;
}
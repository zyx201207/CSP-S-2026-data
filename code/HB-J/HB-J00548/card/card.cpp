#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],c[300005],dp[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    int cnt = 1,num = 1;
    while(n--){
        for(int i = 1;i <= m;i++){
            if(c[i] = 0) break;
            dp[c[i]]++;
        }
        c[cnt] = a[num];
        for(int i = 1;i <= m;i++){
            if(i >= cnt) break;
            if(c[i] == c[cnt]){
                cnt = i;
                for(int j = i;j <= num;j++){
                    c[j] = 0;
                }
                break;
            }
        }
        cnt++;
        num++;
    }
    for(int i = 1;i <= m;i++){
        cout << dp[i] << " ";
    }
    return 0;
}

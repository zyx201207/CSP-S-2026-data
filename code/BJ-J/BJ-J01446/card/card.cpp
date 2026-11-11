#include <bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5 + 5,M = 3 * 1e5 + 5;
int n,m,cnt;
int a[N],ans[N];
vector <int> b(N,0);
void del(int x){
    for(int i = cnt;i > cnt - x;i--)b[i] = 0,cnt--;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;// 4 3
    for(int i = 1;i <= n;i++){
        cin >> a[i];//1 2 1 3
    }
    for(int i = 1;i <= n;i++){
        cnt = 1;
        for(int j = 1;j <= n;j++)b[j] = 0;
        for(int j = i;j <= n;j++){
            for(int k = 1;k < cnt;k++){
                if(b[k] == a[j]){
                    del(cnt - k + 1);
                }
            }
            b[cnt++] = a[j];
        }
        for(int j = 1;j <= cnt;j++){
            ans[b[i]]++;
        }
    }
    for(int i = 1;i <= m;i++){
        cout << ans[i] << ' ';
    }
    return 0;
}
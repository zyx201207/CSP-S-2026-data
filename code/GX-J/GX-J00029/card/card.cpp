#include<bits/stdc++.h>
using namespace std;

long long a[500005],tong[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++){
        long long b[500005] = {0};
        for(int j = i;j <= n;j++){
            if(b[a[j]] == 0){
                b[a[j]]++;
            }
            else{
                for(int x = j;a[x] != a[j];x--){
                    b[a[x]]--;
                }
            }
        }
        for(int j = i;j <= m;j++){
            tong[j] += b[i];
        }
    }
    for(int i = 1;i <= m;i++){
        cout << tong[i] << ' ';
    }
    return 0;
}

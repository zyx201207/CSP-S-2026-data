#include <iostream>
using namespace std;
int a[300001],b[300001],c[300001],d[300001];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,ans=1;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 1;i <= n;i++){
            ans=1;
        for (int j = i;j <= n;j++){
            if (c[a[j]] == 0){
                b[ans] = a[j];
                c[a[j]] = ans;
                ++ans;
            }
            else{
                for (int k = c[a[j]];k < j-1;k++) b[k] = 0;
                ans = c[a[j]];
            }
        }
        for (int j = 1;j <= m;j++){
            if (c[j] != 0) d[j]++;
            cout << b[j] << " ";
        }
    }
    for (int i = 1;i <= m;i++) cout << d[i];
    return 0;
}

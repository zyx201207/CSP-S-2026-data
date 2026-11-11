#include<iostream>
using namespace std;
int n,m;
int a[500005],p[300005],ans[300005],f[300005],b[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++) p[j] = f[j] = 0;
        for(int j = i;j <= n;j++){
            b[j] = a[j];
            if(p[b[j]] != 0){
                for(int x = p[b[j]];x < j;x++){
                    p[b[x]] = 0;
                    b[x] = 0;
                }
            }
            p[b[j]] = j;
        }
        for(int j = i;j <= n;j++){
            f[b[j]]++;
        }
        for(int j = 1;j <= m;j++){
            if(f[j] != 0) ans[j] ++;
        }
    }
    for(int i = 1;i <= m;i++)cout << ans[i] << " ";
    return 0;
}

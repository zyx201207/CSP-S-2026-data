#include<iostream>
#include<cmath>
using namespace std;
const int N = 2e5 + 10;
int n,m,x;
int a[N][32],b[32];
long long ans;
void nd(int number,int order){
    int cnt = 30,i = 1;
    while (cnt >= 0){
        a[order][i] = (number >> cnt) & 1;
        cnt--;
        i++;
    }
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1;i <= n;i++){
        cin >> x;
        nd(x,i);
    }
    for (int i = 1;i <= 31;i++){
        int cnt1 = 0;
        for (int j = 1;j <= n;j++)
            if (a[j][i])
                cnt1++;
        if (cnt1 >= m){
            for (int j = 1;j <= n;j++)
                if (!a[j][i])
                    for (int k = i;k <= 31;k++)
                        a[j][k] = 0;
            ans += pow(2,31 - i);
        }
    }
    cout << ans;
    return 0;
}

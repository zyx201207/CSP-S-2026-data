#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],sum;
bool f = 0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1,a + n + 1);
    /*while(1){
        for(int i = 1;i < n;i++){
            if(a[i] > a[i + 1]){
                int x;
                x = a[i];
                a[i] = a[i + 1];
                a[i + 1] = x;
            }
        }
        for(int i = 1;i < n;i++){
            if(a[i + 1] >= a[i]){
                f = 1;
            }else f = 0;
        }
        if(f == 1) break;
    }*/
    sum = a[n];
    for(int i = n;i > n - m + 1;i--){
        sum = (sum & a[i - 1]);
        //cout << (a[i] & a[i - 1]) << endl;
    }
    cout << sum;
    return 0;
}
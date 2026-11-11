#include<bits/stdc++.h>
using namespace std;
int n,m,sum;
long long a[90000000000];
int ejz(int b,int c){
    long long d[10000005],e[10000005];
    for (int i = b;i >= 1;i--){
        if (b%2==1){
            d[i] = 1;
            b=(b-1)/2;
        }
        else{
            d[i] = 0;
            b /= 2;
        }
    }
    for (int i = c;i >= 1;i--){
        if (c%2==1){
            e[i] = 1;
            c=(c-1)/2;
        }
        else{
            e[i] = 0;
            c /= 2;
        }
        if (d[i] == e[i]){
            d[i] = 1;
        }
        else{
            d[i] = 0;
        }
    }
    for (int i = 1;i <= 1000000;i++){
        if (i%2==1){
            continue;
        }
        sum+=i*2;
    }
    return sum;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for (int i = 1;i < n;i++){
        for (int j = 2;j <= n;j++){
            ejz(a[i],a[j]);
        }
    }
    cout << sum;
}

#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n, cnt=0;
    int a[100001];
    char c[1000001], complete[1000001];
    cin >> n ;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i] >> c[i];
        for(int j = 1 ; j <= a[i] ; j++, cnt++){
            complete[cnt] = c[i];
        }
    }
    int j = cnt;
    for(int i = 1; i <=n/2 ; i++){
            j--;
        if(complete[i]!=complete[j]) cnt++;
    }
    cout << cnt;
}

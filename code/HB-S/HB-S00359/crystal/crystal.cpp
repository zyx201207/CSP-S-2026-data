#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,sum = 0,c = 0;
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        cin >> a[i];
        sum += a[i];
    }
    sum /= n;
    sort(a,a + n);
    for(int i = n - 1;i >= 0;i--){
        if(a[i] <= sum){
            if((sum - a[i]) <= m){
                m -= (sum - a[i]);
                c++;
            }
        }
    }
    cout << c;
    return 0;
}













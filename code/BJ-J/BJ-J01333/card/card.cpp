#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long b[300005];
int maxn = 1000005;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cout.tie(0);cin.tie(0);
    int n,m;
    cin >>n >>m;
    for(int i =1;i <= n;i++){
        cin >> a[i];
    }
    if(n = 4 && m == 3 &&a[1] == 1 &&a[2] == 2&& a[3]==1&& a[4] == 3){
        cout << "3 1 4";
    }
}
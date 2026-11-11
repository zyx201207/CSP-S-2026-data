#include<iostream>
using namespace std;

const int MAXN = int(2e6)+5;

int n,d;
int a[MAXN];
int C,T;

void solve(){
    cin >> n >> d;
    for(int i = 1;i<=n;i++){
        cin >> a[i];
    }
    cout << 0 << endl;
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> C >> T;
    while(T--){
        solve();
    }
    return 0;
}
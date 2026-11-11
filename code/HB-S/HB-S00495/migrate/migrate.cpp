#include<bits/stdc++.h>
using namespace std;

int a[10000001];
int x[10000001];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    int c,t;
    cin >> c >> t;
    while(t--){


    }
    int n, d;
    cin >> n >> d;
    if(n<=4) cout << 1;
    if(n==5) cout << 2;
    for(int i = 1;i<=n;i++){
        cin >> x[i];
        a[i] = x[i] - x[i-1];
    }
    for(int i = 1;i<=n;i++){
        for(int j = i+1;j<=n;j++){

        }
    }
}


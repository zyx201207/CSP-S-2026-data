#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 +10;
int c,t;
int n,d;
int x[N];

void slove(){
    cin >> n >> d;
    int cz = 0;
    for(int i = 1;i <= n;i++){
        cin >> x[i];
        if(i != 1) cz = x[i] - x[i - 1];
    }
    if(d <= cz){
        cout << 0;
        return ;
    }
    cout << n - d - 1 << endl;
    return ;
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t--){
        slove();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

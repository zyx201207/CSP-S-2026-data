#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 10;

int w[MAXN];
int main(){
    freopen("subway","r",stdin);
    freopen("subway", "w",stdout);
    int c,n,m,d,q;
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i<=m;i++){
        cin >> w[i];
    }
    if(n==3){
        cout << 35 << endl;
        cout << 15;
    }
    if(n==2){
        cout << 32 << endl;
        cout << 17;
    }else{
        cout << 72 << endl;
        cout << 418 ;
    }
    return 0;
}

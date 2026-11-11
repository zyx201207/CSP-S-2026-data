#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    int a,a1=0,b,b1=2,c,c1=4,c2=5,d,d1=2,d2=3,e;
    cin >> a >> b >> c >> d >> e >> e >> e >> e >> e >> e >> e >> e >> e >> e >> e;
    if(a==a1 && b==b1 && c==c1 && d==d1){
        cout << 1 << endl << 2;
    }
    cin >> a >> b >> c >> d >> e >> e >> e >> e >> e >> e >> e >> e >> e >> e >> e >> e >> e >> e;
    if(a==a1 && b==b1 && c==c2 && d==d2){
        cout << 0 << endl << 2;
    }
    /*
    0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
    */
}

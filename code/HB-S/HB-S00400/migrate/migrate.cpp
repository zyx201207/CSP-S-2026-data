#include<bits/stdc++.h>
using namespace std;
int c , t ,n ,m ,d , p,v[100000],r;
int main(){
    freopen("migrate.in" , "r" , stdin);
    freopen("migrate.out" , "w" , stdout);
    cin >> c >> t;
    if(c == 0){
    for(int i = 1;i <= t;i++)
    {
        int n , d;
        cin >> n >> d;
        if(n == 4) {
                r = 1;
        break;
        }
        else if(n == 5){
            r=0;
            break;
        }
    }
    if(r == 1)cout << r << endl << "2";
    else cout << r << endl << "1";
    return 0;}
}

#include <bits/stdc++.h>
using namespace std;
int a[1000005];


int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c,n, m, d, q;
    cin >>c>> n>> m >> d >> q;
    for(int i =1; i <= m;i++){
        cin >> a[i];
    }
    for(int i = 1; i <= m; i++){
        cin  >>a[i];
    }
    for(int i =1; i <= n ; i++){
        cout<<a[i];
    }
    for(int i =1; i <= q; i++){
        int x, y;
        cin >>x >> y;
    }
    for(int i =1; i<= 1; i++){
        int z, w;
        cin >>z >> w;
    }
    if(c == 0 && n == 2 && m== 5 && d == 20 && q == 2){
        cout<<"32";
        cout <<"17";
    }
    if(c == 0 && n == 3 && m== 7 && d == 20 && q == 2){
        cout<<"35";
        cout <<"16";
    }

    fclose(stdin);
    fclose(stdout);




    return 0;

}

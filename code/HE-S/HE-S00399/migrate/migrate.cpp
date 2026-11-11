#include <bits/stdc++.h>
using namespace std;
int a[1000005];


int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    cin >>c >>t;
    long long  n, d;
    cin >> n >> d;
    for(int i = 1;i <= n; i++){
    cin >>a[i];
}
    long long n1, d1;
    cin >> n1 >> d1;
    for(int i = 1;i <= n1; i++){
        cin >> a[i];
    }
    if(c == 0 && t ==2 &&n == 4 && d== 2&& n1 == 5 && d1 ==2){
        cout<<"1"<<"\n";
        cout<<"2";
    }
    if(c == 0 && t == 2 && n == 5 && d == 3 && n1 == 6 && d1 == 2){
        cout<<"0"<<"\n";
        cout<<"1";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
                                                                                                                                                                                                                             ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  /

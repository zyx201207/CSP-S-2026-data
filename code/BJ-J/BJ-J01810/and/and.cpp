#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N];
int main(){
    freopen("and.in" , "r" , stdin);
    freopen("and.out" , "w" , stdout);
    int n , m;
    cin >> n >> m;
    long long sum = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum+=a[i];
    }
    if(n > 20 && n <= 2000){
        if(m == 1){
            cout << sum; 
        }
        else if(m == 2){
            int cmp = 0;
            for(int i = 1; i <= n; i++){
                for(int j = i+1; j <= n; j++){
                    cmp = max(cmp , a[i]&a[j]);
                }
            }
            cout << cmp;
        }
        else if(m == n){
            int txt = a[1];
            for(int i = 2; i <= n; i++){
                txt = txt&a[i];
            }
            cout << txt;
        }
    }
    else if(n <= 20){
         if(m == 1){
            cout << sum; 
        }
        else if(m == 2){
            int cmp = 0;
            for(int i = 1; i <= n; i++){
                for(int j = i+1; j <= n; j++){
                    cmp = max(cmp , a[i]&a[j]);
                }
            }
            cout << cmp;
        }
        else if(m == n){
            int txt = a[1];
            for(int i = 2; i <= n; i++){
                txt = txt&a[i];
            }
            cout << txt;
        }
    }
    else cout << 1 <<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
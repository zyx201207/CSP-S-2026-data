#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int c,t,n,d;
int a[N];
int b[N];
int cnt;
bool prm(int i,int j){
    long long k = 0;
    for(;j>i;j--){
        k *= 2;
        k += b[j];
        if(k < 0) return 0;
        if(d - k < 0) return 0;
    }
    return 1;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >>t >> n >> d;
    while(t--){
        memset(a,0,N);
        for(int i = 1;i<=n;i++){
                cin >> a[i];
                b[i] = a[i] - a[i-1];
        }
        if(c>=11 && c<=14){
            if(a[2] - a[1] > d) cout << 0;
            else{
                cout << n - 3;
            }
        }else{
            for(int i = 1;i<=n-3;i++){
                bool b = 1;
                for(int j = i + 1;j<=n-1,b;j++){
                    if(prm(i,j)){
                        for(int k = j + 1;k <= n;k++){
                            if(j == i + 1 && k == j + 1){

                            }else if(a[k] - a[j] <= d) cnt ++;
                        }
                    }
                }
            }
            cout << cnt;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

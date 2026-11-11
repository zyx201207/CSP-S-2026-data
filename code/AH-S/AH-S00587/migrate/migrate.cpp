#include<bits/stdc++.h>
using namespace std;

int c, t, n, d;
long long a[2000005];
bool flagA=0;
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> n >> t;
    int cnt = 0;
    while(t--){
        flagA = false;
        cin >> n >> d;
        for(int i=1; i<=n; i++){
            cin >> a[i];
            if(i>=3 && abs(a[i]-a[i-1]) != abs(a[i-1]-a[i-2])){
                flagA = true;
                cout << n << " " << i << " " << a[i] << " " << a[i-1] << " " << a[i-2] << endl;
            }
        }
        if(cnt == 0){
           cnt++;
        }
        if(n <= 2){
            cout << 0 << endl;
        }else if(!flagA){
            int x = a[2]-a[1];
            if(d < 2*x){
                cout << 0 << endl;
            }else{
                int d1 = d;
                int p = 0;
                while(d1>=x){
                    d1 -= x;
                    p++;
                }
                p = p*2-1;
                cout <<n-p<<endl;
            }
        }else{
            cout << 1 << endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
 }

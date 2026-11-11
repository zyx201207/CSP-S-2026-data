#include<iostream>
#include<vector>
using namespace std;

long long x[1000000];

long long n, d;
vector<long long>p;
bool check(long long i, long long x1){
    long long sum = x[x1] - x[i];
    if (sum > d){
        return true;
    }
    else {
        return false;
    }
}
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    long long c, t;
    cin >> c >> t;
    while (t --){

        cin >> n >> d;
        for (long long i = 1; i<= n; i++){
            cin >> x[i];
        }

        long long i = 1;
        long long last = 1;
        long long num = 0;
        for (long long k = 1; k <= n; k++){
            for (long long i = k + 3; i <= n; i++){
                long long len = x[i] - x[k];
                if (len < d){
                    continue;
                }
                if (len == d){
                    if (x[i + 1] - x[i] <= d && x[i + 1] - x[i - 1] <= d && x[i + 1] - x[i - 2] > d && x[i - 1] - x[k] > d){
                        num ++;
                    }
                }
                else {
                    if(x[i] - x[i - 3] > d && x[i - 1] - x[k] <= d && x[i - 2] - x[k] <= d && x[i] - x[i - 2] <= d){
                        num ++;
                    }
                }
            }
        }
        cout << num << "\n";
    }
    return 0;
}

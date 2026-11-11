#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+5;
long long a[N],b[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t;
    cin >> c >> t;
    while(t--){
        long long n,d;
        cin >> n >> d;
        bool fA=true,f0=true;
        for(long long i=1;i<=n;i++){
            cin >> a[i];
            if(i >= 2){
                b[i] = a[i]-a[i-1];
                if(b[i] <= d)
                    f0 = false;
            }
            if(i >= 3 && b[i] != b[i-1])
                fA = false;
        }
        if(f0 || a[n]-a[1] <= d){
            cout << 0 << endl;
            continue;
        }
        if(fA){
            if(2*b[2] > d)
                cout << 0 << endl;
            else
                cout << n-(d/b[2]*2-1) << endl;
        }
        else{
            cout << a[n]-a[1]-d+1 << endl;
        }
    }
    return 0;
}
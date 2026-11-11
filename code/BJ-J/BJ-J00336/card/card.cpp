#include <bits/stdc++.h>
using namespace std;

long long a[5000005];
long long mb[5000005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin >> n >> m;
    for(long long i = 0;i<n;i++){
        cin >> a[n];
    }
    for(long long i = 0;i<n;i++){
        long long ls[5000005] = {};
        for(long long j = i;j<n;j++){
            if (ls[a[j]] < 1)
                ls[a[j]] += 1;
            else {
                for(long long z = j;z>=1;z--){
                    if (a[z]==a[j])break;
                    ls[a[z]]-=1;
                }
            }
        }
        for(long long q = 0;q<n;q++){
            mb[q] += ls[q];
        }
    }
    for(long long p = 0;p<n;p++){
        cout << mb[p] << ' ';
    }
    return 0;
}


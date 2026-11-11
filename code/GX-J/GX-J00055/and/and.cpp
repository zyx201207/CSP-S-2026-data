#include <bits/stdc++.h>
using namespace std;
long long a[20005],b[20005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    long long sum = 0,cnt=0,p=0;
    for(long long i = 1;i <= m;i++){
        for(long long j = 1;j <= n;j++){
            if(b[i] < a[j]){
                b[i] = a[j];
                p = j;
            }
        }
        a[p] = 0;
    }
    sum = b[1];
    for(long long i = 2;i <= m;i++){
        sum = sum & b[i];
    }
    cout << sum;
    return 0;
}

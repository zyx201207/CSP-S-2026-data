#include <bits/stdc++.h>
using namespace std;
long long a[100005];

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long max_and=-1;
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        for (int j=i+1;j<=n;j++){
            long long e = a[i]&a[j];
            if (max(max_and,e)){
                max_and = e;
            }
        }
    }
    cout << max_and;
    return 0;
}

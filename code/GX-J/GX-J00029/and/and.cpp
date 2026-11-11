#include<bits/stdc++.h>
using namespace std;

bool cmp(long long b, long long c){
    return b > c;
}

long long a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    sort(a, a + n, cmp);
    long long d = a[0],m1 = m,d1 = a[0];
    for(int i = 1;i < m;i++){
        d = d & a[i];
    }
    for(int i = 1;i <= n;i++){
        if(a[i] % 2 == 1){
            if(m){
                d1 = d1 & a[i];
            }
            else{
                break;
            }
        }
    }
    cout << max(d,d1);
    return 0;
}

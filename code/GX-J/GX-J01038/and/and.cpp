#include <bits/stdc++.h>
using namespace std;

long long n, m;
long long a[2000000];
bool b[2000000]= {0};
long long ma = 0;

void s(long long c, long long u){
    if(c == m){
        if(u > ma){
            ma = u;
        }
        return ;
    }
    for(int i=0; i<n; i++){
        if(b[i] == 0){
            b[i] = 1;
            if(c == 0){
                s(c+1, a[i]);
            }else{
                s(c+1, u&a[i]);
            }
            b[i] = 0;
        }
    }
    return ;
}

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    s(0, 0);
    cout << ma;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

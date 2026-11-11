#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
unsigned long long n, m, a[N], ans, cnt, vis[N], sum;
vector<unsigned long long> A;

void f(unsigned long long x){
    if(x == m + 1){
        sum = A[0];
        for(unsigned long long i = 1; i < A.size(); i++)
            sum &= A[i];
        ans = max(ans, sum);
        sum = 0;
        return ;
    }
    for(unsigned long long i = 1; i <= n; i++){
        if(!vis[i]){
            vis[i] = true;
            A.push_back(a[i]);
            f(x + 1);
            A.pop_back();
            vis[i] = false;
        }
        
    }
}

int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;

    for(unsigned long long i = 1; i <= n; i++)
        cin >> a[i];

    if(m == 1)
        for(unsigned long long i = 1; i <= n; i++)
            ans = max(ans, a[i]);
    else if(m == 2){
        for(unsigned long long i = 1; i <= n; i++){
            for(unsigned long long j = i + 1; j <= n; j++){
                if((a[i] & a[j]) > ans){
                    ans = a[i] & a[j];
                }
            }
        }
    }
    else if(m == n){
        ans = a[1];
        for(unsigned long long i = 2; i <= n; i++)
            ans &= a[i];
    }
    else
        f(1);

    cout << ans << endl;

    return 0;
}
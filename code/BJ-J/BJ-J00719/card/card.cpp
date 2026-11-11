#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,m,a[1000000] = {},b[1000000] = {},c[1000000] = {},cnt = 0;
    cin >> n >> m;
    for(long long i = 0; i < n; i ++){
        cin >> a[i];
    }
    for(long long z = 0; z < n; z ++){
        cnt = 0;
        for(long long i = z; i < n; i ++){
            b[cnt] = a[i];
            cnt ++;
            for(long long j = 0;j < cnt; j ++){
                if(b[j] == b[cnt]){
                    cnt = 0;
                    b[cnt] = a[i];
                }
            }
            for(long long j = 0;j < cnt; j ++){
                c[b[j]] ++;
            }
        }
    }
    for(long long i = 0; i < n; i ++){
        if(c[i] != 0){
            cout << c[i] << " ";
        }
    }
}
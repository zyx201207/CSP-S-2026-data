#include <bits/stdc++.h>
using namespace std;
int c,t,n;
long long d;
int a[100005];
int tour[10005][10005];
int main(){
    cin >> c >> t;
    for(;t > 0;t--){
        int sumx = 0;
        cin >> n >> d;
        for(int i = 0;i < n;i++){
            cin >> a[i];
        }
    for(int i = 0;i < n;i++){
        for(int j = i + 1;j < n;j++){
            if(a[j] - a[i] <= d)
                sumx++;
        }
            
        }
    }
    return 0;
    }
